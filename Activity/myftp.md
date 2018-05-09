TCP
cmd:upload
id:文件名
size:文件大小
data:data,tar.gz
/* 高清原图abc.jpg，打码的高清图片abc_mask.jpg，打码压缩的图片abc_low_mask.jpg，block文件abc_block.txt
{0；坐标；识别内容}
{1；坐标；识别内容}
{2；坐标；识别内容}

cmd:remove
id:文件名
/////////////////////////////
cmd:keywordsearch
key:关键字
date:日期
range:0:20//20:40
return-
img:低清图片
date:放置日期
id:id if empty,

cmd:detailsearch
id:id
return-
img:高清
blockcounter:

cmd:identify
id:id
blocks:"0:xxxxx;1:xxxxx;...."
return-
result:true/false
qrcode:二维码(文件名)
