
window.addEventListener('load', function() {
    let removeEl = document.getElementById("remove_el");
    removeEl.addEventListener('click', function () {
        console.log("i tyt")
        
        console.log(document.getElementById("remove").value)
        
        // let xhttp = new XMLHttpRequest();
        // xhttp.open("POST", `/api/v1/animals/${id}`, true);
        // xhttp.onreadystatechange = function() {
        //     if (this.readyState == 4 && this.status == 200) {
        //        console.log(this.response)
        //     }
        // }
        // xhttp.send();
    })
    let addEl = document.getElementById('add')
    addEl.addEventListener('click', function () {
        console.log("yyyhyyy")
        console.log(document.getElementById("breed").value)
        console.log(document.getElementById("description").value)
        console.log(document.getElementById("fact1").value)
        document.getElementById("fact2").value
        document.getElementById("fact3").value
        document.getElementById("fact4").value
        document.getElementById("fact5").value
        document.getElementById("fact6").value
        document.getElementById("fact7").value
        console.log(document.getElementById("picture").value)
        let xhttp = new XMLHttpRequest();
        xhttp.open("POST", '/api/v1/animals/create', true);
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
               console.log(this.response)
            }
        }
        xhttp.send();
    })
});