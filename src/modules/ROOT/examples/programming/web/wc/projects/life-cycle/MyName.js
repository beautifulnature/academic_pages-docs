export default class MyName extends HTMLElement {
    constructor(){
        super();

        this.innerText = `Hello, my name is NO NAME`;
    }

    static get observedAttributes() {
        return['full-name'];
    }

    attributeChangedCallback(name, oldValue, newValue){
        if(name == 'full-name'){
            this.innerText = `Hello, my name is ${newValue}`;
        }
    }
}