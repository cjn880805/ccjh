//符石
//18hell_stone.h
//2001-02-03

ITEM_BEGIN(CIwiz_fushi);

virtual void create(int nFlag = 0)		
{
	set_name("符石","stone");
	
	set("value", 0l);
	
	set("no_drop", 1);
	set("no_give", 1);
	set("no_get", 1);
	
	set("owner", "lanwood");		//纪录符石的主人。
	
	//	set("backdoor", "地狱之门");	//纪录玩家传送出来的房间，初始设置为地狱之门。
	
};

//设置主人
void init()
{
	CContainer * env = environment();
	
	if(! querystr("owner")[0] && userp(env) )
	{
		set("owner", env->querystr("id"));
		return;
	}
}

int query_autoload()
{
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting())
		return notify_fail("你正在战斗中，无法使用符石。");
	
	if(me->querymap("corps"))
		AddMenuItem("飞出地狱", "$0trans $1 0", me); 
	
	if(me->querymap("corps"))
		AddMenuItem("进入地狱", "$0trans $1 1", me); 
	
	if(me->querymap("corps"))
		AddMenuItem("地狱经历", "$0task $1 2", me);
	
	SendMenu(me);
	
    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0)
		return do_go(me, atol(arg));
	
	if(me->query("grant") > CChar::GRANT_PLAYER && strcmp(comm, "goto") == 0)
		return do_goto(me, arg);
	
	if(strcmp(comm, "task") == 0)
		return do_task(me);
	
	return CItem::handle_action(comm, me, arg);
}

int do_goto(CChar * me, char * arg)
{
	char msg[255];
	
	if(! strlen(arg))
		return notify_fail("你想去哪里？");
	
	CRoom * env = load_room(arg);
	
	message_vision("只见$N拿出符石，默默祈祷。一道金光闪过，$P消失在空气中。", me);
	me->delete_temp("pending");
	me->move(env);
	tell_room(env, snprintf(msg, 255, "光芒逐渐散去，%s的身影露了出来。", me->name()), me);
	
	return 1;
}

int do_go(CChar * me , int dest)
{
	char msg[255];
	
	const char * ro;
	
	if(me->is_fighting())
		return notify_fail("你正在战斗。");
	
	if(dest == 0)	//出地狱
	{
		char tmp[40];
		
		strcpy(tmp, me->environment()->querystr("base_name"));
		tmp[4] = 0;
		
		if ( DIFFERSTR(tmp, "野外"))		//判断是否处于地狱。
			return notify_fail("你现在不在地狱之中，怎么能飞出地狱呢？");
		
		me->set_temp("backdoor", me->environment()->querystr("base_name"));		//纪录飞出地狱时所处的房间。
		me->add("modify/power", -1);
		
		int lv = me->query("18dy/task");
		
		if ((!lv) || lv == 0 || lv != me->query("18dy/level") || lv == 1)
			ro = "地狱之门1";
		
		if (lv == 2) ro = "地狱之门2";
		if (lv == 3) ro = "地狱之门3";
		if (lv == 4) ro = "地狱之门4";
		if (lv == 5) ro = "地狱之门5";
		if (lv == 6) ro = "地狱之门6";
		if (lv == 7) ro = "地狱之门7";
		if (lv == 8) ro = "地狱之门8";
		if (lv == 9) ro = "地狱之门9";
		if (lv == 10) ro = "地狱之门10";
		if (lv == 11) ro = "地狱之门11";
		if (lv == 12) ro = "地狱之门12";
		if (lv == 13) ro = "地狱之门13";
		if (lv == 14) ro = "地狱之门14";
		if (lv == 15) ro = "地狱之门15";
		if (lv == 16) ro = "地狱之门16";
		if (lv == 17) ro = "地狱之门17";
		if (lv == 18) ro = "地狱之门18";
					
	}
	
	if(dest == 1)	//入地狱
	{	
		//判断是否处于地狱/
		char tmp[40];
		
		strcpy(tmp, me->environment()->querystr("base_name"));
		tmp[4] = 0;
		
		if (!DIFFERSTR(tmp, "野外"))		//判断是否处于地狱。
			return notify_fail("你现在正在地狱之内，不需要再入地狱了。");
		
		strcpy(tmp, me->querystr_temp("backdoor"));
		tmp[4] = 0;
		if ( DIFFERSTR(tmp, "野外") )
			return notify_fail("时间过得太久，符石已不记得来时的路。");			
		
		ro = me->querystr_temp("backdoor");		//返回飞出地狱所处的地点。	
	}
	
	if(me->query("mp") < 30)
		return notify_fail("你的法力不足！");
	
	me->add("mp", -100);
	me->delete_temp("pending");
	
	message_vision("$YEL$N在空中划出一道门，抬腿跨了进去。" , me);
	
	CRoom * r = load_room(ro);
	tell_room(r, snprintf(msg, 255, "$HIB空中现出一道门，%s从中走了下来。", me->name()), me);
	me->move(r);	    
	
	return 1;
}

int do_task(CChar * me)
{	
	
	char msg[255];
	
	int power = me->query("modify/power");
	int boss = me->query("modify/boss");
	int num = me->query("modify/num");
	int stu = me->query("modify/study");
	
	if ((power < 1) && (boss < 1) && (num < 1) && (stu < 1))
		return notify_fail("$WHT符石不愿意理你！$COM");
	
	message_vision(snprintf(msg, 255, "$YEL$N现在一共杀了%ld魔怪，除掉了%ld个BOSS！$COM", power, boss), me);
	message_vision(snprintf(msg, 255, "$MAG$N现在一共完成了%ld个任务，获得技能%ld点。$COM", num, stu), me);
	
	return 1;
}

/*
//使用之可以补充HP和MP
int do_use(CChar * me, CContainer * target)
{
if(target && me != target) return 0;	//只能对自己使用

  int need1 = (me->query_apply("max_hp") - me->query("hp")) / 3;
  int need2 = (me->query_apply("max_mp") - me->query("mp")) / 2;
  
	if(need1 < 1) need1 = 0;
	if(need2 < 1) need2 = 0;
	
	  int point = need1 > need2 ? need1 : need2;
	  
		if(! point) return notify_fail("你体力充沛，符石不对你发生作用。");
		
		  int provide = query("modify/power") / 30;		
		  if(! provide) return notify_fail("你对符石的修炼不足，无法使用。");
		  
			int resume = provide < point ? provide : point;
			
			  add("modify/power", - resume * 30);
			  UpdateMe();
			  
				me->receive_healing("hp", resume * 3);
				me->receive_healing("mp", resume * 2);
				
				  if(me->is_fighting())
				  {
				  CSkill::combat_magic_animate(me, me, 4);
				  me->SendMagicState();
				  me->set_use_time(3);
				  }
				  else
				  me->SendState();
				  
					return 1;
					}
*/

//主人死了，该物消失
void owner_is_killed(CChar * killer)
{
	destruct(this);
}

ITEM_END;
