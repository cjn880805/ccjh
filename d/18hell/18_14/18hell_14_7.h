//18hell_14.h
//十八地狱第十层寒冰地狱第7房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_14_7);

virtual void create()			//Call it when Room Create
{
	set_name("寒冰地狱");
	
	add_npc("diyu_shizhe14");

};

virtual int do_look(CChar * me)
{
	say("狱中，冰山雪地，寒风呼啸，远处重叠的围城积淀着恺恺白雪，从兽形的围城大门内喷射出雪花和寒风，形状各异的冰柱上，冻结了无数的罪人骷髅残躯。", me);
	say("稍后，冰川侧的冰山下罪人们蜷伏冰窟雪地之中，有的赤身裸体，有的只穿裤衩，个个冻得直打哆嗦，真是“路有冻死骨，冰川尸骨寒”。鬼差们持刀操棒，戒备森严，唯有冰山冰塔中有微火闪烁。 ", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
