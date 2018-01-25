let id = null;

window.addEventListener('load', function () {
    console.log("looaddd")
    $('#myTable').find('tr').click( function(){
       id = $(this).index();
    });
    
    // $('body').on('click', '#submitMark', function () {
    //     console.log("user_id "+document.getElementById('submitMark').value)
    //     let user_id = document.getElementById('submitMark').value;
    //     console.log("id "+id)
    //     let mark = document.getElementById((id-1).toString()).value;
    //     console.log(mark)
    //     let xhttp = new XMLHttpRequest();
    //     let data = new FormData();
    //     data.append("mark",mark)
    //     data.append("user_id",user_id)
    //     xhttp.open("POST", `/api/v1/setmark`,true);
    //     xhttp.onreadystatechange = function() {
    //         if (this.readyState == 4 && this.status == 200) {
    //                 console.log(this.response)
                   
    //         }
    //     }
    //     xhttp.send(data);
    // });
   
})