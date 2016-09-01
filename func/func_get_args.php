<?php ## Использование fuct_get_args().
function myecho() {  
    $args=func_get_args();
  foreach ($args as $v) {
    echo "$v<br>\n"; // выводим элемент
  }
}
// отображаем строки одну под другой
myecho("Меркурий", "Венера", "Земля", "Марс");
?>
