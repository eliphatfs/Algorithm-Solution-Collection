str = "";
var cnt = 0;
for (var i=1000;i<=1188;i++)
	$.get("index.php/main/show/"+i, function(data) {
			str += data + "KSDLSADEVEFMNVV";
			cnt++;
			if (cnt == 189)
			{
				var blob = new Blob([str],{type:"text/plain"});
				console.log(URL.createObjectURL(blob));
			}
		}
	)
