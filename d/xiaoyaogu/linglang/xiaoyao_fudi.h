//xiaoyao_fudi.h 琅擐福地
//秦波 2003、3、15

XiaoYao_BEGIN(CRXiaoYao_fudi);

virtual void create()
{
	set_name( "琅擐福地");
	set("no_autosave",1);
	set("long","这是座圆形石室，左边镶在石壁的一块大水晶，约有铜盆大小，光亮便从水晶中朦朦胧胧的透入。从水晶向外瞧去，只见碧绿水流不住幌动，鱼虾水族来回游动，极目所至，竟无尽处。");

	add_door("石室1", "逍遥谷琅擐福地石室1", "逍遥谷琅擐福地");
	add_door("石室2", "逍遥谷琅擐福地石室2", "逍遥谷琅擐福地");
	add_door("石室3", "逍遥谷琅擐福地石室3", "逍遥谷琅擐福地");
	add_door("石室4", "逍遥谷琅擐福地石室4", "逍遥谷琅擐福地");
	add_door("琅擐福地洞门", "逍遥谷琅擐福地洞门", "逍遥谷琅擐福地");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

XiaoYao_END;
