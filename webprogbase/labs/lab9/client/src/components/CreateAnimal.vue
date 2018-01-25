<template>
<div class="create_form">
    <div>
        <label for="breed">Breed:</label>
        <input type="text" v-model="animal.breed" class="input" id="breed"  name="breed" value="" required></input>
    </div>
    <div>
        <label for="description">Description:</label>
        <input type="text" class="input"  v-model="animal.description" id="description"  name="description" value=""  required></input>
    </div>
    <div>
        <label for="facts"> 7 Facts:</label>
        <input type="text"class="input"  v-model="animal.fact1" id="fact1"  name="fact1" value="" required></input>
        <input type="text"class="input"  v-model="animal.fact2" id="fact2"  name="fact2" value="" required></input>
        <input type="text"class="input"  v-model="animal.fact3" id="fact3"  name="fact3" value="" required></input>
        <input type="text" class="input" v-model="animal.fact4" id="fact4"  name="fact4" value="" required></input>
        <input type="text" class="input" v-model="animal.fact5" id="fact5"  name="fact5" value=""  required></input>
        <input type="text" class="input" v-model="animal.fact6" id="fact6"  name="fact6" value=""  required></input>
        <input type="text" class="input" v-model="animal.fact7" id="fact7"  name="fact7" value=""></input>
        <label for="picture">Picture:</label>
        <input type="file" @change="uploadImage" class="upload" accept="image/*"  id ="picture" name="picture" ref="file" required>
        </div>
        <div class="form-group danger-alert" v-if="error">
                    <h3>{{error}}</h3>
        </div>
        <button  @click="create"  id="add" class="OK" >OK</button>
        
    </div>
</template>
<script>
import BookService from '@/services/animals'
import PictureInput from 'vue-picture-input'
import AnimalApi from '@/services/animals'
export default {
    name: 'CreateAnimal',
    components: {
        PictureInput
    },
    props: ['animaladd'],
    data () {
        return {
            animal: {
                breed: null,
                description: null,
                fact1: null,
                fact2: null,
                fact3: null,
                fact4: null,
                fact5: null,
                fact6:null,
                fact7:null,
                picture:null
            },
            error: null,
        }
    },
    methods: {
        create: async function(event) {
            this.error = null
            const allFieldsFilledIn = Object.keys(this.animal).every(key => !!this.animal[key])
            if (!allFieldsFilledIn) {
                this.error = 'Please fill in all the required fields.'
                return;
            }
            let newAnimal = await  AnimalApi.addAnimal(this.animal)
            console.log("response"+newAnimal)
            this.$emit('newAnimalAdd', newAnimal); 
            this.animal.breed = null;
            this.animal.description = null;
            this.animal.fact1 = null;
            this.animal.fact2 = null;
            this.animal.fact3 = null;
            this.animal.fact4 = null;
            this.animal.fact5 = null;
            this.animal.fact6 = null;
            this.animal.fact7 = null;
            this.$refs.file.value = "";
        },
        uploadImage:function(event){
            this.animal.picture = event.target.files[0];
        }
    }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->

<style scoped>
/* create form in main page*/
    .create_form{
        font-family: 'Open Sans Condensed', arial, sans;
        /* width: 1100px; */
        padding: 30px;
        background: #FFFFFF;
        margin-top:44px;
        margin-left: -380px;
       
        box-shadow: 0px 0px 15px rgba(0, 0, 0, 0.22);
        -moz-box-shadow: 0px 0px 15px rgba(0, 0, 0, 0.22);
        -webkit-box-shadow:  0px 0px 15px rgba(0, 0, 0, 0.22);
    }
    .input
    {
        box-sizing: border-box;
        -webkit-box-sizing: border-box;
        -moz-box-sizing: border-box;
        outline: none;
        display: block;
        width: 100%;
        padding: 7px;
        border: none;
        border-bottom: 1px solid #ddd;
        background: transparent;
        margin-bottom: 10px;
        font: 16px Arial, Helvetica, sans-serif;
        height: 45px;
    }
    .OK{
        border-radius: 5px;
        background: #030302;
        color: #E9F3F1;
        padding: 8px 10px 8px 10px;
        margin-top: 40px;
        margin-left: 250px;
        width: 100px; 
    }
    h2{
        font-size:30px;
        margin-top: 30px;
        margin-left: 300px;
    }
    .upload {
        background-color:#F7F9F9;
        font-family: 'Open Sans Condensed', arial, sans;
        font-size: 18px;
        background: #eee;
        border: 1px solid #ccc;
    
        line-height: 1;
        text-align: center;
        padding: 3px;
        width: 300px;
    
    }
    h3{
        font-size:15px;
        color: red;
    }
</style>
