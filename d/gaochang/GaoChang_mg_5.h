//GaoCang_mg_5.h 地狱第一层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_5);

virtual void create()			
{
	set_name("泥犁地狱");

	CDoor * a = add_yewaidoor("west", 6, 20);
	CDoor * b = add_yewaidoor("north", 6, 20);
	CDoor * c = add_yewaidoor("east", 6, 20);
	CDoor * d = add_yewaidoor("south", 6, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("鬼门关", "高昌鬼门关", "高昌泥犁地狱");
	add_npc("dy_master");

	set("long", "阴曹的地狱阴风瑟瑟，密雾萦绕，远处围城隐约可见。远高近低的荒野中，各种男女罪人或仰或卧陷于泥土之中，鬼卒扶着铁犁，鞭打铜牛猛跑，尸浪翻卷，血流成河，罪人肢残腿断，身首分离。低处五马分尸，其中一烈马扬蹄昴首狂嘶，马后一大鬼扬鞭怒吼。近处巨大的岩石下，一巨鬼猛擂神鼓，惊兽辗尸，泥血交溶溅飞。顶部多盏油灯残明，让游客产生似在荒郊却不见天日之感。场景前面兽栏与游客相隔。 ");

};

virtual int do_look(CChar * me)
{
	say("阴曹的地狱阴风瑟瑟，密雾萦绕，远处围城隐约可见。远高近低的荒野中，各种男女罪人或仰或卧陷于泥土之中，鬼卒扶着铁犁，鞭打铜牛猛跑，尸浪翻卷，血流成河，罪人肢残腿断，身首分离。低处五马分尸，其中一烈马扬蹄昴首狂嘶，马后一大鬼扬鞭怒吼。 ", me);
	say("近处巨大的岩石下，一巨鬼猛擂神鼓，惊兽辗尸，泥血交溶溅飞。顶部多盏油灯残明，让游客产生似在荒郊却不见天日之感。场景前面兽栏与游客相隔。 ", me);
	SendMenu(me);
	return 1;
}
YEWAIDOOR_END;
