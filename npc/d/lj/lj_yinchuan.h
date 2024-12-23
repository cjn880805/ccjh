//taijian.h
//秦波 2002-08-01

NPC_BEGIN(CNlj_yinchuan);

virtual void create()
{
	set_name("银川公主", "yinchuan gongzhu");
	set("gender", "女性");
	set("icon", 2);
	
	set("title", "西夏国");
	set("age", 18);
	set("attitude", "friendly");
	set("str", 40);
	set("int", 40);
	set("con", 45);
	set("dex", 40);
	set("per",35);
	
	set("hp",46000);
	set("max_hp", 46000);
	set("no_kill",1);
	
};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * r = load_room("灵州皇宫大门");
	if(r->query("start") && r->query("start")==atoi(me->id(1)) && !me->query("lj/renwu13") 
		&& EQUALSTR(me->querystr_temp("apply/name"),"竹虚") )
	{
		message_vision("\n$HIR银川公主拉着你的手，一双深情的眼睛脉脉的凝视着你。",me);
		me->disable_player("凝视");
		call_out(do_xiangren, 10);
	}
}

static void do_xiangren(CContainer * ob, LONG param1, LONG param2)
{
	CNlj_yinchuan * npc = (CNlj_yinchuan *)ob;
	if(atoi(npc->querystr("owner")))
	{
		CUser * me;
		me=find_online(npc->querystr("owner"));
		if(me)
		{
			me->enable_player();
			message_vision("$HIR良久之后，方才幽幽的说道：“梦郎，我日日夜夜想你，从今后你就是我的驸马了，这回我再也不要和你再分开。”",me);
			message_vision("$HIR你看着面前的公主，心中也是一阵柔情荡漾，想到灵鹫峰上正在痴情等待着的竹虚尊主，",me);
			message_vision("$HIR不由轻声的说道：“公主，这辈子竹虚也永远不会离开你。",me);
			message_vision("$HIR不如你随我去那云雾环绕、了无人烟的缥缈峰上一起过着不会再也不会被人拆开的神仙般的生活吧！",me);
			message_vision("$HIR银川公主满面幸福的闭上了眼睛，转过身倒在你的怀中，喃喃道：不管是去哪里，只要能和你在一起，我都愿意。\n",me);
			
			me->del("lj");
			me->delete_temp("lj");
			me->set("lj/renwu13",1);
			me->add("combat_exp",10000);
			me->UpdateMe();
			tell_object(me, "\n$HIR你完成了“西夏皇宫比武招亲”的任务，获得了10000点的经验奖励。\n");
			
			CContainer * env = load_room("灵州皇宫大门");
			if(env->query("start"))env->del("start");
			env = load_room("灵州皇宫大厅");
			if(env->query("start"))env->del("start");
			env = load_room("灵州皇宫内书房");
			if(env->query("start"))env->del("start");
			
			me->move(load_room("灵州皇宫大门"));
			npc->move(load_room("灵州皇宫大门"));
			npc->set_leader(me);
		}
	}
}
NPC_END;

