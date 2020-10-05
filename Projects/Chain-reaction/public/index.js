/**
 * Todo:
 * 1. Change colours of numbers
 * 2. On collision of numbers, played colour 
 * is given to collided number
 * 3. Emit and receive
 */

/* Elements and selectors */
const $ = document.querySelector.bind(document),
	$All = document.querySelectorAll.bind(document);
	root = $("#root");

/* Namespaces */
let elements = {};
let globals = {
	rows: 8,
	columns: 6,
    critical: {
        corner: 1,
        sidelined: 2,
        bulk: 3
    },
    stt: []
};
let gameState = {
    music: null,
    rows: globals.rows,
    columns: globals.columns
};

let previousStatus = [];

function showAlert(text, type, callback) {
	let alertArea = $("#alerts");

    alertArea.style.display = "block";
    alertArea.style.zIndex = "2";

    alertArea.classList = [];
    if (type === "danger") {
        alertArea.classList.add("danger");
    } else if (type === "warning") {
        alertArea.classList.add("warning");
    } else if (type === "info") {
        alertArea.classList.add("info");
    } else {
        alertArea.classList.add("success");
    }
    alertArea.innerHTML = "<div id='alert-text'><span>" + text + "</span></div>";

    setTimeout(function() {
        alertArea.style.display = "none";
        alertArea.style.zIndex = "0";
        callback();
    }, 3000);
}

function showModal(html, attrs, styles, ...nodes) {
    // todo: implement unclosabillity
    let modal = $("#modal");
    modal.style.display = "block";

    let content = $(".modal-content");
    content.innerHTML = 
        `<span class="modal-close">&times;</span><br>${html ?? ""}`;
    
    if (nodes) {
        nodes.forEach(el => content.appendChild(el));
    }

    Object.keys(styles).forEach(sty => content.style[sty] = styles[sty]);

    window.onclick = function(event) {
        if (event.target == modal) {
            modal.style.display = "none";
        }
    }

    $(".modal-close").onclick = function() {
        modal.style.display = "none";
    }
}

function closeModal(node) {
    if (node) return node.style.display = "none";
    $("#modal").style.display = "none";
}

function ce(name, attrs, styles, props, children, parent) {
    let ele = document.createElement(name);
    if (attrs) {
        Object.keys(attrs).forEach(attr => {
            ele.setAttribute(attr, attrs[attr]);
        });
    }
    if (styles) {
        Object.keys(styles).forEach(sty => {
            ele.style[sty] = styles[sty];
        });
    }
    if (children) {
        children.forEach(child => ele.appendChild(child));
    }
    if (props) {
        Object.keys(props).forEach(prop => ele[prop] = props[prop]);
    }

    if (parent)
    	parent.appendChild(ele);
    else return ele;
}

function addToParent(parent, ...children) {
	if (children)
		children.forEach(child => parent.appendChild(child));
	return parent;
}

function drawGrid(rows, columns, populateFrom, firstTime, graphical) {
	let grid = ce('table', {
		class: "grid table",
		id: "grid"
	});

	let template = [],
        j = 0;
	while (j < rows) {
		let row = ce(
			"tr", 
			{ class: "grid-row", id: "row-" + j }
		);

        if (firstTime) gameState.status.push([]);

		let tds = [],
            i = 0;
		while (i < columns) {
			tds.push(
				ce(
					"td", 
					{ 
                        class: "grid-column", 
                        id: "column-wrap-" + i, 
                        "data-row": j,
                        "data-col": i
                    },
                    null,
                    { 
                        onclick: checkAndPlay
                    },
                    [ce('div', { 
                        id: "column-" + i,
                        "data-row": j,
                        "data-col": i
                    }, null, { 
                        innerHTML: firstTime ? 
                            (graphical ? 
                                "" : 
                                `<span data-col="${i}" data-row="${j}"></span>`) 
                            : populateFrom[j][i].amount
                    })]
				)
			);

            if (firstTime) {
                gameState.status[j].push({ amount: 0, player: "default", player: -1 });
            }

            i += 1;
		}

		addToParent(row, ...tds);
		addToParent(grid, row);
        j += 1;
	}

	return grid;
}

function checkAndPlay(event) {
    /*
    1. store previous grid;
    2. isAlreadyOut? => Next
    */
    let coords = [],
        et = event.target,
        { turns, outPlayers } = gameState;

    coords.push(parseInt(et.getAttribute("data-row")));
    coords.push(parseInt(et.getAttribute("data-col")));

    /* Store grid for undo */
    storeCurrentGrid();

    if (isAlreadyOut()) {
        gameState.turns += 1;
        switchTurn();
        return;
    }
    if (isRightCell(...coords)) {
        testAndAct(...coords);
        gameState.turns += 1;

        setCountOfCells();

        stt = gameState.status;

        turnUtils(gameState.turns);
    }
    toggleUndo("enable");
}

function turnUtils(turns) {
    setCountOfCells();
    switchTurn();

    if (turns >= gameState.playerNumber) {
        let result = isGameOver();
        if (result.gameOver) {
            showAlert(
                gameState.players[result.winner].colour.toUpperCase() + " wins!", 
                "info",
                resetGame
            );
        }
    }
}

function resetGame(dontAsk) {
    let reset = false;
    if (dontAsk) {
        if (confirm("Are you sure you want to reset this game?")) {
            init();
            reset = true;
        }
    } else {
        init();
        reset = true;
    }
}

function isRightCell(row, column) {
    let { status, currentPlayer } = gameState;

    if (
        (status[row][column].player === currentPlayer // the cell is owned by current player
        || status[row][column].player === -1) // the cell is yet blank
        // the player is not already out
    ) {
        return true;
    }
    return false;
}

function isAlreadyOut() {
    let { outPlayers, currentPlayer } = gameState;
    if (outPlayers.includes(currentPlayer)) {
        return true;
    }
    return false;
}

function switchTurn() {
    let rem = gameState.turns % gameState.playerNumber;
    switchColours(rem);

    gameState.currentPlayer = rem;
    let colour = gameState.players[gameState.currentPlayer].colour;

    $All(".settings-button").forEach(btn => {
        btn.style.background = colour;
    });

    if ($("#turn-info"))
    $("#turn-info").innerHTML 
            = colour[0].toUpperCase() + colour.slice(1);
}

function switchColours(num) {
    $All(".grid-column").forEach(col => {
        col.style.border = "1px solid " + gameState.players[num].colour;
    });

    $("#grid").style.border = "2px solid " + gameState.players[num].colour;
}

function isGameOver() {
    let nonZeroPast = false;
    let over = true;
    let winner = -1;
    gameState.players.forEach((p, i) => {
        if (!nonZeroPast) {
            if(p.count !== 0) {
                nonZeroPast = true;
                winner = i;
            }
        } else if (nonZeroPast) {
            if(p.count !== 0) {
                over = false;
            }
        }

        if (p.count === 0) {
            gameState.outPlayers.push(i);
        }
    });

    if (over) {
        return { gameOver: true, winner };
    } else {
        return { gameOver: false };
    }
}

function setCountOfCells() {
    let { status } = gameState;

    gameState.players.forEach(p => {
        p.count = 0;
    });

    status.forEach((a, row) => {
        a.forEach((cell, column) => {
            let cellDom = $(formId(row, column));
            if (!getValue(row, column)) {
                gameState.status[row][column].player = -1;
                if (!gameState.graphical) cellDom.style.color = "white";
            }

            if (cell.player !== -1)
                gameState.players[cell.player].count += 1;

            if (isUnstable(row, column)) {
                if (gameState.graphical) 
                    cellDom.childNodes.forEach(ch => ch.classList.add("shake"));
                else
                    cellDom.classList.add("shake");
            } else {
                cellDom.classList.remove("shake");
                cellDom.classList.add("slow-shake");
            }
        });
    });
}

function testAndAct(row, column) {
    if (isUnstable(row, column)) {
        explode(row, column, position(row, column));
    } else {
        increment(row, column);
    }
}

function getValue(row, column) {
    if (gameState.status[row][column])
        return parseInt(gameState.status[row][column].amount);
    else
        return null;
}

function isUnstable(row, column) {
    let pos = position(row, column);
    if (pos === "corner") {
        if (getValue(row,column) >= globals.critical.corner) {
            return true;
        } else return false
    } else if(pos === "sidelined") {
        if (getValue(row,column) >= globals.critical.sidelined) {
            return true;
        } else return false
    } else {
        if (getValue(row,column) >= globals.critical.bulk) {
            return true;
        } else return false
    }
}

function position(row, column) {
    let sides = 0;
    if (gameState.status[row][column - 1] !== undefined) {
        sides += 1;
    }
    if (gameState.status[row][column + 1] !== undefined) {
        sides += 1;
    }
    if (gameState.status[row - 1] && gameState.status[row - 1][column] !== undefined) {
        sides += 1;
    }
    if (gameState.status[row + 1] && gameState.status[row + 1][column] !== undefined) {
        sides += 1;
    }

    if (sides === 2) return "corner";
    if (sides === 3) return "sidelined";
    if (sides === 4) return "bulk";
}

function explode(row, column, pos) {
    gameState.status[row][column].amount = 0;
    act(row, column, 0);

    $("#audio-player").play();

    if (gameState.status[row][column - 1] !== undefined) {
        testAndAct(row, column-1);
    }
    if (gameState.status[row][column + 1] !== undefined) {
        testAndAct(row, column+1);
    }
    if (gameState.status[row - 1] && gameState.status[row - 1][column] !== undefined) {
        testAndAct(row-1, column);
    }
    if (gameState.status[row + 1] && gameState.status[row + 1][column] !== undefined) {
        testAndAct(row+1, column);
    }
}

function lread(key) {
    return atob(sessionStorage.getItem(key));
}

function lwrite(key, value) {
    return sessionStorage.setItem(key, btoa(value));
}
function increment(row, column) {
    gameState.status[row][column].amount += 1;
    act(row, column, getValue(row,column));
    return;
}

function act(row, column, value, awardToPlayer) {
    let { currentPlayer, players } = gameState;
    let rightPlayer = awardToPlayer !== undefined ? awardToPlayer : currentPlayer;
    gameState.status[row][column].player = rightPlayer;

    let colour = rightPlayer !== -1 ? players[rightPlayer].colour : "white";

    if (gameState.graphical) {
        $(formId(row, column)).innerHTML = "";
        let i = 0;
        while (i < value) {
            let particle = ce("div", {
                class: "particle " + colour + "-sphere circle ball",
                "data-row": row,
                "data-col": column
            });

            if (value === 3) {
                particle.classList.add("three-p");
            } else if (value === 2) {
                particle.classList.add("two-p");
            } else if (value === 1) {
                particle.classList.add("one-p");
            }

            $(formId(row, column)).appendChild(particle);

            i += 1;
        } 
    } else {
        $(formId(row, column)).style.color = colour;
        $(formId(row, column)).innerHTML = "<span>" + value + "</span>";
    }      
}

function formId(row, column) {
    return `#row-${row} #column-wrap-${column} #column-${column}`;
}

/* Undo preparations */
function toggleUndo(state) {
    if (state === "enable") {
        gameState.undoAllowed = true;
        $("#undo-button").disabled = false;
    } else if (state === "disable") {
        gameState.undoAllowed = false;
        $("#undo-button").disabled = true;
    }
}

function storeCurrentGrid() {
    let grid = $("#grid");
    gameState.grid = grid;
    // previousStatus = gameState.status;
    gameState.statusHistory[gameState.statusHistory.length] = (gameState.status);
    if(gameState.statusHistory.length -2>-1)
    previousStatus = gameState.statusHistory[gameState.statusHistory.length -2] 
    // console.log("gameState.prvious: ",gameState)
}

function rewind() {
    let gridWrap = $("#grid-wrap");
    let shty = gameState.statusHistory;
    // console.log("gameState.previous: ",previousStatus);
    let newGrid = drawGrid(
        gameState.rows,
        gameState.columns,
        previousStatus
    );
    

    //console.log("inside rewind");
    gameState.status = previousStatus;
    gridWrap.removeChild(gridWrap.childNodes[0]);
    gridWrap.appendChild(newGrid);
    populateCells(previousStatus)
    gameState.turns = gameState.turns -1;
    switchTurn()
    turnUtils()

    gameState.statusHistory = shty.slice(0, shty.length - 1);
    // console.log("gameState.statusHistory: ",gameState.statusHistory.length)
}


function init() {
    /* Elements */
    root.innerHTML = "";
    createAndLoadElements();

    /* Reset state */
    resetState();

    /* Load grid */
    loadGrid();

    /* First colour setup */
    switchTurn();

    if (lread("chrct-mode") === "graphical"){
        gameState.graphical = true;
    }

    if (lread("chrct-players") && parseInt(lread("chrct-players"))) {
        gameState.playerNumber = parseInt(lread("chrct-players"));
    }

    // if (confirm("Use graphical mode? This is unsuitable for low-resource systems."))
    //     gameState.graphical = true;
    // let numofplayers = prompt("Number of players (in digits and at least 2)?");

    // if (parseInt(numofplayers))
    //     gameState.playerNumber = numofplayers;
}

function createAndLoadElements() {
    elements.alerts = ce('div', {
        class: "alerts",
        id: "alerts"
    });

    elements.modal = ce('div', {
        class: "modal",
        id: "modal"
    });

    elements.undoButton = ce('button', {
        class: "button settings-button",
        id: "undo-button",
        // disabled: "true"
    }, null, {
        innerHTML: "Undo",
        onclick: function() {
            toggleUndo("enable");
            rewind();
        }
    });

    elements.resetButton = ce('button', {
        class:"button settings-button",
        id: "reset-btton"
    }, null, {
        innerHTML: "Reset",
        onclick: function (e) {
            resetGame();
        }
    });

    elements.turnInfo = ce('button', {
        class: "button settings-button",
        id: "turn-info",
        disabled: true
    }, { background: "black", color: "black" });

    elements.settings = ce('div', {
        class: "settings",
        id: "settings"
    }, null, null, [
        elements.undoButton,elements.resetButton, elements.turnInfo
    ]);

    elements.gc = ce('div', {
        class: "container background",
        id: "grid-wrap"
    });

}

function loadGrid() {
    elements.grid = drawGrid(globals.rows, globals.columns, null, true, gameState.graphical);

    addToParent(elements.gc, elements.grid);

    addToParent(
        root, elements.modal, elements.alerts, 
        elements.gc, elements.settings
    );
}

function resetState() {
    gameState.status = [];
    gameState.turns = 0;
    gameState.statusHistory = [];
    gameState.undoAllowed = false;
    gameState.currentPlayer = 0;
    gameState.previousStatus = [];
    gameState.players = [ {
        colour: "red",
        count: 0
    }, {
        colour: "green",
        count: 0
    }, {
        colour: "blue",
        count: 0
    }, {
        colour: "yellow",
        count: 0
    }, {
        colour: "cyan",
        count: 0
    }, {
        colour: "magenta",
        count: 0
    }, {
        colour: "white",
        count: 0
    }, {
        colour: "violet",
        count: 0
    }, {
        colour: "slateblue",
        count: 0
    }, {
        colour: "tomato",
        count: 0
    }, {
        colour: "dodgerblue",
        count: 0
    }, {
        colour: "lightgray",
        count: 0
    } ];
    gameState.playerNumber = 2;
    gameState.graphical = false;
    gameState.outPlayers = [];
}

function populateCells(status) {
    // assuming the grid is already loaded.
    status.forEach((row, j) => {
        row.forEach((column, i) => {
            act(j, i, column.amount, column.player);
        });
    });
}

function loadFromState(state, status) {
    gameState = state;
    gameState.status = status;
    populateCells(status);
    turnUtils();
}

init();