
// Membuat lingkaran
#include <bits/stdc++.h> 
using namespace std; 
  
// Fungsi membuat lingkaran
void printPattern(int radius) { 
  
  // Nilai tengah dari lingkaran 
  float dist; 
  
  // Arah Horizontal
  for (int i = 0; i <= 2 * radius; i++) { 
  
    // Arah Vertikal
    for (int j = 0; j <= 2 * radius; j++) { 
      dist = sqrt((i - radius) * (i - radius) +  
                  (j - radius) * (j - radius)); 
  
      // Jarak dari tiap radius dan print bintang
      if (dist > radius - 0.5 && dist < radius + 0.5)  
        cout << "*"; 
      else 
        cout << " ";       
    } 
  
    cout << "\n"; 
  } 
} 
  
// Definisi radius/diameter lingkaran
int main() { 
  int radius = 6; 
  printPattern(radius); 
  return 0; 
} 

