
function check (input){
    let pattern=/^[a-z][a-zA-z0-9]+(?:[ ,-][A-Za-z0-9]+)*$/g
    if (!input.value.match(pattern)) {
          input.setCustomValidity("string must begin with lowercase letter and may contain separator( ,-_)");
    }else {
        // input is valid -- reset the error message
        input.setCustomValidity('');
    }
}
function checkName (input){
    let pattern=/^[A-Z][a-z]+/g
    if (!input.value.match(pattern)) {
          input.setCustomValidity("breed must begin with uppercase letter,the last letters must be lowercase(there must be only one word )");
    }else {
        // input is valid -- reset the error message
        input.setCustomValidity('');
    }
}
function checkDescription(input){
    let pattern=/^[A-Z][^.?!]+((?![.?!]['"]?\\s["']?[A-Z][^.?!]).)+[.?!]+/g
    if (!input.value.match(pattern)) {
          input.setCustomValidity("string must end with dot,exclamation point,question mark,in other case, the sentence will not be counted.First letter must be uppercase");
    }else {
        // input is valid -- reset the error message
        input.setCustomValidity('');
    }
}
function checkFile(sender) {
 let pattern = /([^\s]+(\.()(jpg|jpeg|png|gif|bmp))$)/g
  if (!sender.value.match(pattern)) {
    alert("Invalid file selected, valid files are jpg,jpeg,png,gif,bmp");
    sender.value=''
    return false;
  }
  else {
    return true;
  }
}
