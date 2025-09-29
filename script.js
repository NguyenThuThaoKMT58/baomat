function openTab(name) {
  var contents = document.getElementsByClassName('tabcontent');
  for (let i = 0; i < contents.length; i++) {
    contents[i].classList.remove('active');
  }
  document.getElementById(name).classList.add('active');
}

// Caesar demo
function caesarEncrypt() {
  let text = document.getElementById('caesarText').value;
  let key = parseInt(document.getElementById('caesarKey').value);
  let result = text.replace(/[A-Za-z]/g, c => {
    let base = c <= 'Z' ? 65 : 97;
    return String.fromCharCode((c.charCodeAt(0) - base + key) % 26 + base);
  });
  document.getElementById('caesarResult').textContent = result;
}
function caesarDecrypt() {
  let text = document.getElementById('caesarText').value;
  let key = parseInt(document.getElementById('caesarKey').value);
  let result = text.replace(/[A-Za-z]/g, c => {
    let base = c <= 'Z' ? 65 : 97;
    return String.fromCharCode((c.charCodeAt(0) - base - key + 26) % 26 + base);
  });
  document.getElementById('caesarResult').textContent = result;
}

// Dummy placeholders for others
function affineEncrypt(){ document.getElementById('affineResult').textContent = 'Affine Encrypt chưa code'; }
function affineDecrypt(){ document.getElementById('affineResult').textContent = 'Affine Decrypt chưa code'; }
function columnarEncrypt(){ document.getElementById('columnarResult').textContent = 'Columnar Encrypt chưa code'; }
function columnarDecrypt(){ document.getElementById('columnarResult').textContent = 'Columnar Decrypt chưa code'; }
function vigenereEncrypt(){ document.getElementById('vigenereResult').textContent = 'Vigenere Encrypt chưa code'; }
function vigenereDecrypt(){ document.getElementById('vigenereResult').textContent = 'Vigenere Decrypt chưa code'; }
function playfairEncrypt(){ document.getElementById('playfairResult').textContent = 'Playfair Encrypt chưa code'; }
function playfairDecrypt(){ document.getElementById('playfairResult').textContent = 'Playfair Decrypt chưa code'; }
