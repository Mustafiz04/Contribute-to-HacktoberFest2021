import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class IpAddressFinder extends Frame implements ActionListener{
	JTextField tf;
	JLabel l;
	JButton b;

	IpAddressFinder()
	{
		tf = new JTextField();
		tf.setBounds(50,50,150,20);
		l = new JLabel();
		l.setBounds(50,100,250,20);
		b  = new JButton("Find IP");
		b.setBounds(50,150,95,30);
		b.addActionListener(this);
		this.add(b);
		this.add(l);
		this.add(tf);
		this.setSize(400,500);
		this.setLayout(null);
		this.setVisible(true);
		// setDefaultCloseOperation(3);
	}
	public void actionPerformed(ActionEvent e){
		try
		{
			String host = tf.getText();
			String ip  = java.net.InetAddress.getByName(host).getHostAddress();
			l.setText("Ip of "+host+" is: "+ip);
		}
		catch(Exception exc)
		{
			exc.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new IpAddressFinder();
	}
}