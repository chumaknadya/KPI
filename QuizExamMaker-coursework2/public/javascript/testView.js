let model = {
    time:null,
    test_id:null
}
let interval;
let minutes = 0;
let seconds = 0;
window.addEventListener('load', function () {
    getTime();
    //demoFromHTML()
    FinishTestclick();
})
 function getTime(){
    let time;
    console.log(document.getElementById('test_id').value)
    let id = parseInt(document.getElementById('test_id').value)
    model.test_id = id;
    let xhttp = new XMLHttpRequest();
    let data = new FormData();
    data.append("id",id);
    xhttp.open("POST", `/api/v1/testTime`,true);
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            
            model.time = JSON.parse(this.response)[0].test_limit;
            time = model.time.split(':')
            minutes = time[1];
            seconds = time[2];
            $(".finishTest").show();  
            countdown('timerText')
            
            
        }
    }
    xhttp.send(data);
    
}
function countdown(element) {
    interval = setInterval(function() {
        var el = document.getElementById(element);
        if(seconds == 0) {
            if(minutes == 0) {
                el.innerHTML = "countdown's over!";                
                clearInterval(interval);
                window.location.replace('/')
                return;
            } else {
                minutes--;
                seconds = 60;
            }
        }
        if(minutes > 0) {
            var minute_text = minutes + (minutes > 1 ? ' minutes' : ' minute');
        } else {
            var minute_text = '';
        }
        var second_text = seconds > 1 ? 'seconds' : 'second';
        el.innerHTML = minute_text + ' ' + seconds + ' ' + second_text + ' remaining';
        seconds--;
    }, 1000);
}
function getQuestionsById() {
    let xhttp = new XMLHttpRequest();
    let data = new FormData();
    data.append("id",model.test_id);
    xhttp.open("POST", `/api/v1/questions`,true);
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            console.log(this.response)
            console.log(JSON.parse(this.response))
            for(let i = 0; i < JSON.parse(this.response).length; i++){
                    console.log("yviiiii")
            }
        }
    }
    xhttp.send(data);
}
function getAnswersById(){

}
function FinishTestclick(){
    $(".finishTest").one("click",function(){
       //getQuestionsById();
       demoFromHTML();
       
       
    })
}
function closePage(){
    window.location.replace('/')
}
function demoFromHTML() {
        $('.pdf').append('<div class="parent">');  
        console.log($('.test_design')[0].children)
         
        $('.parent').append(`<h2>${$('.test_design')[0].children[0].innerHTML}<//h2>`);
        for(let i = 3; i < $('.test_design')[0].children.length-1;i++){
            if($('.test_design')[0].children[i].className == "question") {
               $('.parent').append(`<h3>${$('.test_design')[0].children[i].innerText}</h3>`);
            }
            if($('.test_design')[0].children[i].className == "textInp") {
                if($('.test_design')[0].children[i].children[0].value == "") {
                    $('.parent').append(`<h4>Answer: none</h4>`);
                } else{
                    $('.parent').append(`<h4>Answer: ${$('.test_design')[0].children[i].children[0].value}</h4>`);
                }
            }
            if($('.test_design')[0].children[i].className == "dropdown") {
                let index = $('.test_design')[0].children[i].childNodes[1].selectedIndex;
                if(index == 0) {
                    $('.parent').append(`<h4>Answer: none</h4>`);
                } else {
                    $('.parent').append(`<h4>Answer:${$('.test_design')[0].children[i].children[0][index].innerText}</h4`);
                }
            }
            if($('.test_design')[0].children[i].className == "multiply") {
                   let length = $('.test_design')[0].children[i].children.length
                   $('.parent').append(`<div><h4>Answer(s):</h4></div>`);
                   let count = 0;
                   for(let j = 0; j < length; j++) {
                        if($('.test_design')[0].children[i].children[j].checked == true) {
                            $('.parent').append(`<h4>${j}. ${$('.test_design')[0].children[i].children[j].defaultValue}</h4>`);
                            count++
                        }
                   }
                   if(count == 0) {
                        $('.parent').append(`<h4>none</h4>`);
                   }
            }

        }
        $('.pdf').append('</div>');  
        var pdf = new jsPDF('p', 'pt', 'letter');
        // source can be HTML-formatted string, or a reference
        // to an actual DOM element from which the text will be scraped.
        let source = $('.pdf')[0];

        specialElementHandlers = {
            // element with id of "bypass" - jQuery style selector
            '#bypassme': function (element, renderer) {
                // true = "handled elsewhere, bypass text extraction"
                return true
            }
        };
        margins = {
            top: 80,
            bottom: 60,
            left: 40,
            width: 522
        };
        // all coords and widths are in jsPDF instance's declared units
        // 'inches' in this case
        pdf.fromHTML(
            source, // HTML string or DOM elem ref.
            margins.left, // x coord
            margins.top, { // y coord
                'width': margins.width, // max width of content on PDF
                'elementHandlers': specialElementHandlers
            },

            function (dispose) {
                // dispose: object with X, Y of the last line add to the PDF 
                //          this allow the insertion of new lines after html
                //pdf.save('Test.pdf');
            }
            , margins
        );
       let pdfFormat = pdf.output(); 
       let data = new FormData();
       
       data.append("data" , pdfFormat);
       data.append("test_id" ,model.test_id);
       data.append("user_id" ,document.getElementById('userId').value);
       let xhttp = new XMLHttpRequest();
       xhttp.open("POST", `/api/v1/result`,true);
       xhttp.onreadystatechange = function() {
           if (this.readyState == 4 && this.status == 200) {
                 console.log(this.response)
                 closePage();
             }
        }
        xhttp.send(data);

        
    }