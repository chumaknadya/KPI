$(window).on('load', function() { 

    editTestTittle();
    editPageTittle ();
    addNewQuestion ();
    optionSelected();
    $(function() {
        $('.Close').click(function () {
            $('#mymodal').modal("hide");
        });
        $('.Change').click(function () {
           // $('form').submit();
        });
    
        $(document).on("click", "#editPageTittle", function () {
            $('#mymodal').modal("show");
        });
        $(document).on("click", "#editTestTittle", function () {
            $('#mymodal').modal("show");
        });
    });
    saveTest();
});
function saveTest(){
    $("#saveButton").click(function(){
        let data = new FormData();
        //let hours = document.getElementById('hours').value;
        let minutes = document.getElementById('minutes').value;
        let seconds = document.getElementById('seconds').value;
        let status = $("#selectstatus option:selected" ).text();

        let time = "00:" + minutes +":"+seconds;
        console.log(time)
        data.append("test_limit",time);
        data.append("test_status",status);
        let xhttp = new XMLHttpRequest();
        xhttp.open("POST", `/api/v1/test/save`,true);
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                    console.log(this.response)
                    $('.last_save').show()
            }
        }
        xhttp.send(data);
        
    })
}

function collectorsForm(){
    $("#newCollector").click(function(){
        // $("#newCollector").hide()
    })
}
function editTestTittle () {
    $(".testTittle").each(function() {
        $(this)
          .mouseover(function() { $("#editTestTittle").show() })
          .mouseleave(function() { $("#editTestTittle").hide()});
    })
}
function editPageTittle () {
    $(".pageTitle").each(function() {
        $(this)
          .mouseover(function() { $("#editPageTittle").show() })
          .mouseleave(function() { $("#editPageTittle").hide()});
    })
}
function addNewQuestion () {
    $("#addNewQuestion").click(function(){
        $("#formForNewQuestion").show();
        $("#addNewQuestion").hide();
        //clickOneForMultiplyChoice();
        $("#close-form-for-new-question").click(function(){
            if(document.getElementById('questionline').value != null )
                document.getElementById('questionline').value = "";
            if(document.getElementById('dropDownText').value != null)
                document.getElementById('dropDownText').value = "";
            if(document.getElementById('multiplyBodyText').value!= null)
                document.getElementById('multiplyBodyText').value = "";
            $("#multitable tr").slice(1).remove();
            $("#droptable tr").slice(1).remove();
            $("#formForNewQuestion").hide();
            $("#addNewQuestion").show();
        })
        // addNewMultiplyChoice();
        // deleteChoice();
    })
   
    addNewMultiplyChoice();
    deleteChoice();
}
function addNewMultiplyChoice(){
    $("#addmultiplychoice").click(function(){
        console.log("click new multiple")
         $("#multiply-body").append("<tr><td><div style='display:flex; flex-wrap:nowrap;'><div style='flex-grow: 0; padding-right:15px;'><input disabled type='radio'></div> <div style='flex-grow: 1; padding-right:10px;'><div style='flex-grow:1'> <textarea name='multiplyChoiceBody' class='form-control ng-untouched ng-pristine ng-valid'></textarea></div></div><div style='min-width:100px; text-align:center;display:none;'><input style='width:20px; height:20px;' name='checkIfToggleMultiply'  type='checkbox' ></div><div style='min-width:100px; text-align:center;'> <div style='flex-grow: 0;'> <button class='btn btn-danger' id='deleteChoice' type='button'> <i class='glyphicon glyphicon-trash'></i> Delete </button></div></div></td></tr>")
    });
   
}
function  deleteChoice() {
    $('body').on('click', '#deleteChoice', function() {
        //$(this).parent().parent().remove();
        $(this).closest('tr').remove();
     });
}
function optionSelected(){
   
    $('#dropdowBox').change(function() {
        // $(this).val() will work here
           if($('textarea#questionline').val('') != null)
                $('textarea#questionline').val('')
           if( $(this).find(':selected').data('id')=="TextInput"){
              console.log("Text Input");
              ifTextInputSelected();
           }
           if( $(this).find(':selected').data('id')=="MultipleChoice"){
             console.log("MultipleChoice");
             ifMultiplyChoiceSelected();
           }
           if( $(this).find(':selected').data('id')=="Dropdown"){
            console.log("Dropdown")
            ifDropDownSelected()
           }

    });
    addDropDownChoice();
    ifSubMitButtonClick();
    ifSubmitButtonDropDowclick();
    ifSubmitButtonMultipleClick();
}
function ifSubMitButtonClick(){
    $("#submitButton").click(function (){
        let data = new FormData();
        let question = document.getElementById('questionline').value;
        data.append('question',question)
        data.append('question_name', document.getElementById('question_name').value)
        data.append('question_type',"TextInput");
        let xhttp = new XMLHttpRequest();
        xhttp.open("POST", `/api/v1/test/create/textinput`,true);
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                console.log(this.response)
                closeForm ();
                addQuestionToBody()
            }
        }
        xhttp.send(data);
    })
}
function ifTextInputSelected(){
    $('#multiply_choice').hide();
    $("#multitable tr").slice(1).remove();
    $('#settings').hide();
    $('#dropdown').hide();
    $('#submitButtonMultiply').hide();
    $("#submitButtonDropDown").hide();
    $("#droptable tr").slice(1).remove();
    $("#submitButton").show();
    if(document.getElementById('dropDownText').value != null)
        document.getElementById('dropDownText').value = "";
    if(document.getElementById('multiplyBodyText').value!= null)
        document.getElementById('multiplyBodyText').value = "";
    //$("#submitButton").click(function (){
    //     let data = new FormData();
    //     let question = document.getElementById('questionline').value;
    //     data.append('question',question)
    //     data.append('question_name', document.getElementById('question_name').value)
    //     data.append('question_type',"TextInput");
    //     let xhttp = new XMLHttpRequest();
    //     xhttp.open("POST", `/api/v1/test/create/textinput`,true);
    //     xhttp.onreadystatechange = function() {
    //         if (this.readyState == 4 && this.status == 200) {
    //             console.log(this.response)
    //             closeForm ();
    //             addQuestionToBody()
    //         }
    //     }
    //     xhttp.send(data);
    // })
}
function ifMultiplyChoiceSelected(){
    $("#multiply_choice").show();
    $('#dropdown').hide();
    $("#submitButton").hide();
    $("#submitButtonDropDown").hide();
    $("#droptable tr").slice(2).remove();
    $("#submitButtonMultiply").show();
    if(document.getElementById('dropDownText').value != null)
        document.getElementById('dropDownText').value = "";
   // ifSubmitButtonMultipleClick()
}
function clickOneForMultiplyChoice(){
    $("#submitButtonMultiply" ).one( "click", function() {
        let data = new FormData();
        let question = document.getElementById('questionline').value;
        let choice = document.getElementsByName('multiplyChoiceBody');
        let checkButton = document.getElementsByName('checkIfToggleMultiply');
        console.log(checkButton)
        data.append('question',question);
        data.append('question_name', document.getElementById('question_name').value)
        data.append('question_type',"MultipleChoice");
        let arrOfAnswerValue = [];
        let arrOfAnswerCheck = [];
        for (let i = 0; i < choice.length;i++) {
            arrOfAnswerValue.push(choice[i].value);
            arrOfAnswerCheck.push(checkButton[i].checked)
        }
        data.append('answerBody',arrOfAnswerValue)
        data.append('answerCheck',arrOfAnswerCheck)
        let xhttp = new XMLHttpRequest();
        xhttp.open("POST", `/api/v1/test/create/multichoice`,true);
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                console.log(this.response)
                closeForm();
                addQuestionToBodyMultiply();
            }
        }
        xhttp.send(data);
    });
}
function ifSubmitButtonMultipleClick(){
    $("#submitButtonMultiply").click(function (){
        let data = new FormData();
        let question = document.getElementById('questionline').value;
        let choice = document.getElementsByName('multiplyChoiceBody');
        let checkButton = document.getElementsByName('checkIfToggleMultiply');
        console.log(checkButton)
        data.append('question',question);
        data.append('question_name', document.getElementById('question_name').value)
        data.append('question_type',"MultipleChoice");
        let arrOfAnswerValue = [];
        let arrOfAnswerCheck = [];
        for (let i = 0; i < choice.length;i++) {
            arrOfAnswerValue.push(choice[i].value);
            arrOfAnswerCheck.push(checkButton[i].checked)
        }
        data.append('answerBody',arrOfAnswerValue)
        data.append('answerCheck',arrOfAnswerCheck)
        let xhttp = new XMLHttpRequest();
        xhttp.open("POST", `/api/v1/test/create/multichoice`,true);
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                console.log(this.response)
                closeForm();
                addQuestionToBodyMultiply()
            }
        }
        xhttp.send(data);
    })
}
function addDropDownChoice(){
    $('#addDropDownChoice').click(function(){
        console.log("cliick cliick")
        $("#dropdown-body").append("<tr><td style='width:100%'><input name='dropdownBody' type='text' class='form-control ng-untouched ng-pristine ng-valid'></td><td><div style='min-width:100px; text-align:center;display:none;'><input style='width:20px; height:20px;' name='checkIfToggle' type='checkbox'></div></td> <td> <div style='min-width:200px; text-align:right;'> <button class='btn btn-danger btn-sm' id='deleteDropDownChoice' type='button'><i class='glyphicon glyphicon-trash'></i> Delete Choice </button> </div></tr>")
    })
}
function ifSubmitButtonDropDowclick(){
    $("#submitButtonDropDown").click(function (){
        let data = new FormData();
        let question = document.getElementById('questionline').value;
        let choice = document.getElementsByName('dropdownBody');
        let checkButton = document.getElementsByName('checkIfToggle');
        data.append('question',question);
        data.append('question_name', document.getElementById('question_name').value)
        data.append('question_type',"Dropdown");
        let arrOfAnswerValue = [];
        let arrOfAnswerCheck = [];
      
        console.log( document.getElementsByName('checkIfToggle'))
        for (let i = 0; i < choice.length;i++) {
            arrOfAnswerValue.push(choice[i].value);
            arrOfAnswerCheck.push(checkButton[i].checked)
        }
        data.append('answerCheck',arrOfAnswerCheck)
        data.append('answerBody',arrOfAnswerValue)
        let xhttp = new XMLHttpRequest();
        xhttp.open("POST", `/api/v1/test/create/dropdown`,true);
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                console.log(this.response)
                closeForm();
                addQuestionToBodyDropbox();
            }
        }
        xhttp.send(data);
    }) 
}
function ifDropDownSelected(){
    $('#multiply_choice').hide();
    $('#dropdown').show();
    $("#submitButton").hide();
    $("#submitButtonMultiply").hide();
    $("#submitButtonDropDown").show();
    $("#multitable tr").slice(1).remove();
    if(document.getElementById('multiplyBodyText').value!= null)
        document.getElementById('multiplyBodyText').value = "";
    // $('#addDropDownChoice').click(function(){
    //     console.log("cliick cliick")
    //     $("#dropdown-body").append("<tr><td style='width:100%'><input name='dropdownBody' type='text' class='form-control ng-untouched ng-pristine ng-valid'></td><td><div style='min-width:100px; text-align:center;'><input style='width:20px; height:20px;' name='checkIfToggle' type='checkbox'></div></td> <td> <div style='min-width:200px; text-align:right;'> <button class='btn btn-danger btn-sm' id='deleteDropDownChoice' type='button'><i class='glyphicon glyphicon-trash'></i> Delete Choice </button> </div></tr>")
    // })
    deleteDropDownChoice();
    $("#submitButtonDropDown").show();
    // $("#submitButtonDropDown").click(function (){
    //     let data = new FormData();
    //     let question = document.getElementById('questionline').value;
    //     let choice = document.getElementsByName('dropdownBody');
    //     let checkButton = document.getElementsByName('checkIfToggle');
    //     data.append('question',question);
    //     data.append('question_name', document.getElementById('question_name').value)
    //     data.append('question_type',"Dropdown");
    //     let arrOfAnswerValue = [];
    //     let arrOfAnswerCheck = [];
      
    //     console.log( document.getElementsByName('checkIfToggle'))
    //     for (let i = 0; i < choice.length;i++) {
    //         arrOfAnswerValue.push(choice[i].value);
    //         arrOfAnswerCheck.push(checkButton[i].checked)
    //     }
    //     data.append('answerCheck',arrOfAnswerCheck)
    //     data.append('answerBody',arrOfAnswerValue)
    //     let xhttp = new XMLHttpRequest();
    //     xhttp.open("POST", `/api/v1/test/create/dropdown`,true);
    //     xhttp.onreadystatechange = function() {
    //         if (this.readyState == 4 && this.status == 200) {
    //             console.log(this.response)
    //             closeForm();
    //             addQuestionToBodyDropbox();
    //         }
    //     }
    //     xhttp.send(data);
    // })
}

function deleteDropDownChoice(){
    $('#dropdown').on('click', '#deleteDropDownChoice', function() {
        console.log('delete')
        $(this).closest('tr').remove();
     });
}
function closeForm (){
    if(document.getElementById('questionline').value != null )
         document.getElementById('questionline').value = "";
    if(document.getElementById('dropDownText').value != null)
        document.getElementById('dropDownText').value = "";
    if(document.getElementById('multiplyBodyText').value!= null)
        document.getElementById('multiplyBodyText').value = "";
    $("#multitable tr").slice(1).remove();
    $("#droptable tr").slice(1).remove();
    $("#formForNewQuestion").hide();
    
    $("#addNewQuestion").show();
    
}
function addQuestionToBody() {
    let xhttp = new XMLHttpRequest();
    xhttp.open("GET", `/api/v1/test/textinput`)
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            console.log(JSON.parse(this.response)[0].question_body)
            $("#question_body_add").append(`
            <div class="questions">
                <li>
                 ${JSON.parse(this.response)[0].question_body}
                </li>
            </div>`)
        }
    }
    xhttp.send();
}
function addQuestionToBodyMultiply() {
    let xhttp = new XMLHttpRequest();
    xhttp.open("GET", `/api/v1/test/multiply`)
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            console.log(JSON.parse(this.response)[1].question_body)
            console.log(this.response)
            $("#question_body_add").append(`
            <div class="questions">
                <li>
                 ${JSON.parse(this.response)[1].question_body}
                </li>
            </div>`)
            let length = JSON.parse(this.response).length;
            for (let i = 2; i < length; i ++){
                $("#question_body_add").append(`
                  <div class="multi"><input  disabled type="radio"> ${JSON.parse(this.response)[i].answer_body}</input></div>
                `);
            }
        }
    }
    xhttp.send();
}
function addQuestionToBodyDropbox() {
    let xhttp = new XMLHttpRequest();
    xhttp.open("GET", `/api/v1/test/multiply`)
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            console.log(JSON.parse(this.response)[1].question_body)
            console.log(this.response)
            $("#question_body_add").append(`
            <div class="questions">
                <li>
                 ${JSON.parse(this.response)[1].question_body}
                </li>
            </div>`)
            let length = JSON.parse(this.response).length;
           
            $("#question_body_add").append('<select class="drop">')
            $("#question_body_add select").append(`<option></option>`);
            for (let i = 2; i < length; i ++){
                console.log("ldlsldl")
                $("#question_body_add select").append(`
                  <option>${JSON.parse(this.response)[i].answer_body}</option>
                `);
            }
            $("#question_body_add").append('</select>')
        }
    }
    xhttp.send();
}
// @to do
// 
// validation , error
// add question to a body
// bug in dropdown split(",") jsahdjash,askdjd - separate use not an array  !!!!!!
// fix padding in questionline
// button addChoice add 2 element - bug !!!!!!  ------ done
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
