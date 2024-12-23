//taijian.h
//�ز� 2002-08-01

NPC_BEGIN(CNlj_yinchuan);

virtual void create()
{
	set_name("��������", "yinchuan gongzhu");
	set("gender", "Ů��");
	set("icon", 2);
	
	set("title", "���Ĺ�");
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
	CContainer * r = load_room("���ݻʹ�����");
	if(r->query("start") && r->query("start")==atoi(me->id(1)) && !me->query("lj/renwu13") 
		&& EQUALSTR(me->querystr_temp("apply/name"),"����") )
	{
		message_vision("\n$HIR����������������֣�һ˫������۾��������������㡣",me);
		me->disable_player("����");
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
			message_vision("$HIR����֮�󣬷������ĵ�˵���������ɣ�������ҹҹ���㣬�ӽ��������ҵ������ˣ��������Ҳ��Ҫ�����ٷֿ�����",me);
			message_vision("$HIR�㿴����ǰ�Ĺ���������Ҳ��һ�����鵴�����뵽���շ������ڳ���ȴ��ŵ�����������",me);
			message_vision("$HIR����������˵�������������Ⱳ������Ҳ��Զ�����뿪�㡣",me);
			message_vision("$HIR����������ȥ�������ơ��������̵���翷���һ����Ų�����Ҳ���ᱻ�˲𿪵����ɰ������ɣ�",me);
			message_vision("$HIR�������������Ҹ��ı������۾���ת��������Ļ��У��૵���������ȥ���ֻҪ�ܺ�����һ���Ҷ�Ը�⡣\n",me);
			
			me->del("lj");
			me->delete_temp("lj");
			me->set("lj/renwu13",1);
			me->add("combat_exp",10000);
			me->UpdateMe();
			tell_object(me, "\n$HIR������ˡ����Ļʹ��������ס������񣬻����10000��ľ��齱����\n");
			
			CContainer * env = load_room("���ݻʹ�����");
			if(env->query("start"))env->del("start");
			env = load_room("���ݻʹ�����");
			if(env->query("start"))env->del("start");
			env = load_room("���ݻʹ����鷿");
			if(env->query("start"))env->del("start");
			
			me->move(load_room("���ݻʹ�����"));
			npc->move(load_room("���ݻʹ�����"));
			npc->set_leader(me);
		}
	}
}
NPC_END;

