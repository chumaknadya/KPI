<template>  
<div>
            <div class="pag" v-for="page in animalsPages" :key="page">
                   <button  @click="changepage(page)"  class="btn btn-primary"> {{page}} </button>
            </div>   
    </div>
</template>

<script>
export default {
    props: ['animalsPages'],
    methods: {
        changepage: async function(page) {
            this.$emit('changePage', page); 
        }
    }
}   
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style >
    .pag{
        padding:1px;  
        display:inline-block;
    } 
    
 
 
</style>