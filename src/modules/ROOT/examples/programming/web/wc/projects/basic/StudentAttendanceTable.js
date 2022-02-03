export default class StudentAttendanceTable extends HTMLElement {
    constructor() {
        super();

        this.render();
    }

    render(){
        this.innerText = this.getLoadingText();
        this.getStudentList();
    }

    getLoadingText(){
        return `loading...`;
    }

    getStudentList() {
        fetch('./student.json')
        .then(response => {
            return response.json();
        })
        .then(jsonData => {
            this.generateTable(jsonData);
        })
        .catch(e => {
            this.innerText = this.getErrorText();
            console.log(e);
        })
    }

    getErrorText(){
        return `unable to retrieve student list.`;
    }

    generateTable(studentData) {
        let rows = studentData.map((student, index) => {
            return this.getTableRow(index, student.name);
        });

        let table = document.createElement('table');
        table.innerHTML = rows.join('');
        this.appendHTMLToShadowDOM(table);
    }

    appendHTMLToShadowDOM(html){
        this.innerHTML = '';
        let shadowRoot = this.attachShadow({mode: 'open'});
        shadowRoot.append(html);
    }

    getTableRow(index, name){
        let tableRow = `<tr>
                <td>${index + 1}</td>
                <td>${name}</td>
                <td>
                    <input type="checkbox" name="${index}-attendance" />
                </td>
            </tr>`;
        return tableRow;
    }
}