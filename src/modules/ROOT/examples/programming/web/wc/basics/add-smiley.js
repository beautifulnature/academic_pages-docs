class AddSmiley extends HTMLSpanElement {
    constructor(){
        super();

        //lets append a smiley to the the inner text
        this.innerText += '\uD83D\uDE00';
    }
}

customElements.define('add-smiley', AddSmiley, {extends: 'span'});