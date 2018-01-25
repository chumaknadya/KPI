<template>
    <div v-if="animal">
    <div class="modal modal-mask" style="display: block">
            <div class="modal-dialog" role="document">
                <div class="modal-content">
                    <div class="modal-header">
                        <slot name="header"></slot>
                         <h2>Delete</h2>
                    </div>
                    <div class="modal-body">
                        <slot name="body"></slot>
                         Are you sure?
                    </div>
      
                    <div class="modal-footer">
                            <slot name="footer">
                                <button type="button" class="btn btn-default" @click="closeWindow" data-dismiss="modal">Cancel</button>
                                <button id="remove_link"  type="button" @click="removeAnimal()" class="btn btn-primary">Delete</button>  
                            </slot>
                    </div>
            </div>
       </div>
    </div>
   </div>
</template>
<script>
export default {
    name: 'RemoveWindow',
    data () {
        return {  
           show:false
        }
    },
    props:[
       'animal'
    ],
    watch:{
        animal(){
            console.log("watch" + this.animal)
            this.show = Boolean(this.animal)
        }
    },
    methods: {
        closeWindow(){
           console.log("CloseWindow close")
           this.show = false
           this.$emit('close')
        },
        removeAnimal: async function () {
           this.$emit('remove',this.animal)
        }
    }
}
</script>