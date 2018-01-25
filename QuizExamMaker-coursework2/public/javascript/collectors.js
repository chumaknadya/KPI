$(document).ready(function() {
   change(); 
});
function change(){
    $('#chooseColector').change(function() {
        if( $(this).find(':selected').data('id')=="UserCollector"){
            $('#invitorsName').show()
        }
        if( $(this).find(':selected').data('id')=="LinkCollector"){
            $('#invitorsName').hide()
            if(document.getElementById('welcomeMessage').value != null)
               document.getElementById('welcomeMessage').value = "";
        }
        if( $(this).find(':selected').data('id')=="") {
             $('#invitorsName').hide()
        }
    })

}
  
