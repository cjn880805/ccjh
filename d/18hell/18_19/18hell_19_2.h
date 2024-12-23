//18hell_19.h
//十八地狱第十五层冰地狱第2房间

ROOM_BEGIN(CR18hell_19_2);

virtual void create()			//Call it when Room Create
{
	set_name("冰地狱");
	
	add_npc("diyu_shizhe19");

};

virtual int do_look(CChar * me)
{
	say("地狱中布满了岩石，只见一囚笼内的罪人头手露外，双手合十，被二鬼用竹签夹刑奔勒得哇哇直叫。铁笼后一双头鬼手擒囚犯长发在指挥二鬼行刑。", me);
	say("一囚犯鬼被一钉满铁钉的铁板牢牢压住，一大鬼正抡起二锤狠狠锤打铁板，左侧一罪人被五花大绑于石板上，被一鬼役用铁钻分身碎尸。", me);
	say("左侧一石岩边，一受刑者趴在地上，被鬼卒用铁叉叉得体无完肤，靠前一米许，二鬼正用长长的铁夹板给恶人施以夹刑，另一铁板后，若干被捆绑在铁板上的罪人正被众鬼卒用铁叉、铁杆施以酷刑。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
