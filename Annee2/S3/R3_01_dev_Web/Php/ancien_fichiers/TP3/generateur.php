<FORM ENCTYPE="multipart/form-data" ACTION="generateur.php" METHOD="POST">
<input type=hidden name=nbphotos value=photos>
<input type=file name="photo1"><br>
<input type=file name="photo2">
<input type=submit value="Télécharger Photos">
</FORM>


<?php
    if($_SERVER["REQUEST_METHOD"]=== "POST"){
        $nb_photos = $_POST["photos"];
        
    }
?>