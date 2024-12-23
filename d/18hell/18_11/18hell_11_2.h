//18hell_11.h
//十八地狱第七层镬汤地狱第2房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_11_2);

virtual void create()			//Call it when Room Create
{
	set_name("镬汤地狱");
	
	add_npc("diyu_shizhe11");

};

virtual int do_look(CChar * me)
{
	say("岩间，一巨大的特形油锅置于场中平台上，锅中滚油沸腾，断头、残肢在锅中翻滚。一鬼差持棍在锅中搅动，二鬼卒正强行欲将一受刑者投入锅中，二鬼差用杠抬着受刑者，沿石梯将其送往油锅，油锅平台上，有呆若木鸡的受刑者晕倒在墙边，有惊吓得魂不附体的受刑者跪地求饶。", me);
	say("鬼卒中的烧火佬忙碌地在锅边鼓风催火，远处铁锅吊尸依稀可见，大锅中锅小锅的施刑，阶梯式地分布，形成透视，鬼狱中的大规模的行刑作坊内，鬼卒的狞笑声，受刑者的惨叫声响成一遍，鬼卒们的狞笑仿佛在嘲讽那些在阳世作恶多端，在阴曹地府中不思诲改的罪人。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
