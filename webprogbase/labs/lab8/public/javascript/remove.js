

window.addEventListener('load', function() {
    let removeElemet = document.getElementById("remove_link");
    console.log(removeElemet)
    console.log(document.getElementById("username").value)
    console.log(document.getElementById("password").value)
    console.log(window)
    
    removeElemet.addEventListener('click', function() {
        
        let id = window.location.pathname.split( '/' ).pop();
        console.log('/api/v1/animals/'+ id);
        fetch('/api/v1/animals/'+ id,{
            method:'POST',
            headers:{
                Authorization: "Basic " + btoa(App.getState().login + ":" + App.getState().password),
            },
        })
        .then(() => {
                window.location.href = "/animals";
        })
        .catch(err => console.log(err));
    });
   
});