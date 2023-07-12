function Btn(){
    const clickHandler = (button)=>{button.target.classList.toggle("move")}
    return (<button onMouseOver={clickHandler}>Click</button>) ;
}
export default Btn;