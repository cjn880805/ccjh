//18hell_5.h
//十八地狱第一层泥犁地狱第2房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_5_2);

virtual void create()			//Call it when Room Create
{
	set_name("泥犁地狱");
	set("long", "阴曹的地狱阴风瑟瑟，密雾萦绕，远处围城隐约可见。远高近低的荒野中，各种男女罪人或仰或卧陷于泥土之中，鬼卒扶着铁犁，鞭打铜牛猛跑，尸浪翻卷，血流成河，罪人肢残腿断，身首分离。低处五马分尸，其中一烈马扬蹄昴首狂嘶，马后一大鬼扬鞭怒吼。近处巨大的岩石下，一巨鬼猛擂神鼓，惊兽辗尸，泥血交溶溅飞。顶部多盏油灯残明，让游客产生似在荒郊却不见天日之感。场景前面兽栏与游客相隔。 ");
	
	add_npc("diyu_shizhe5");

};

virtual int do_look(CChar * me)
{
	say("阴曹的地狱阴风瑟瑟，密雾萦绕，远处围城隐约可见。远高近低的荒野中，各种男女罪人或仰或卧陷于泥土之中，鬼卒扶着铁犁，鞭打铜牛猛跑，尸浪翻卷，血流成河，罪人肢残腿断，身首分离。低处五马分尸，其中一烈马扬蹄昴首狂嘶，马后一大鬼扬鞭怒吼。 ", me);
	say("近处巨大的岩石下，一巨鬼猛擂神鼓，惊兽辗尸，泥血交溶溅飞。顶部多盏油灯残明，让游客产生似在荒郊却不见天日之感。场景前面兽栏与游客相隔。 ", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
