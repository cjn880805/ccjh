//18hell_17.h
//十八地狱第十三层刀兵地狱第一房间

ROOM_BEGIN(CR18hell_17_1);

virtual void create()			//Call it when Room Create
{
	set_name("刀兵地狱");
	
	add_npc("diyu_shizhe17");

};

virtual int do_look(CChar * me)
{
	say("狱中怪石林立，狂风怒号。石柱、石壁狭窄浑暗，透过隙缝可隐现狱外的围城钢亭，怪石中随时伸出鬼头魔爪。", me);
	say("右侧一雄狮怒吼着从半空中向一罪人猛扑过去，恶人被吓得惊恐万状，另一罪人吓得抱头鼠串，藏头不顾尾，还有一个被吓得晕倒在地；左侧一猛虎以猛虎下山之势从山上向一女罪人猛扑下来，女罪人当场晕倒，另两恶人也吓得魂飞魄散。", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
