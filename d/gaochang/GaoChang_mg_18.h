//GaoCang_mg_18.h 地狱第14层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_18);

virtual void create()			
{
	set_name("铁磨地狱");

	CDoor * a = add_yewaidoor("west", 19, 20);
	CDoor * b = add_yewaidoor("north", 19, 20);
	CDoor * c = add_yewaidoor("east", 19, 20);
	CDoor * d = add_yewaidoor("south", 19, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("刀兵地狱", "高昌刀兵地狱", "高昌铁磨地狱");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("空中及壁上的岩石奇形怪状，洞内岩壁弯曲，曲径小道宽窄不一，洞顶松脂油灯由远至近。", me);
	say("狱中，巨大铁磨被八个鬼差谈笑风声地推辗着，铁磨上两个鬼卒正将两罪人分别贯入磨心，被辗出的肉浆从磨缝中流出，贪婪的小野狐抢食着磨心冒出的血浆，一野狼正沿铁磨探食打转。", me);
	say("远处土坡上二鬼推着幺魔，一受刑者上半身已入磨心，只见臀腿在外。左侧二鬼正用叼杆将罪人四肢绑在一起吊往大磨磨心。", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
