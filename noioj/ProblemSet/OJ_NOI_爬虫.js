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

    
var st = "";
var cnt = 0;
for (var problem = 1001; problem < 1188; problem++)
{
	for (var data = 0; data < 20; data++)
    {
		$.get("http://oj.noi.cn/oj/index.php/main/download/"+problem+"/"+data+".in/1", function (pr, dt) {
                return function (a) {
                    cnt += 1;
                    if (a.indexOf("PHP Error was encountered") == -1 && a.indexOf("You are not allowed to download this file!") == -1) {
                        st += a + "#XCERETLE"+pr+"#"+dt+"#";
                    }
                    if (cnt == 187 * 20) console.log(st);
                }
            }(problem, data)
        );
    }
}