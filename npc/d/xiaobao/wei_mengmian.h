// wei_mengmian.h ����Ů��

NPC_BEGIN(CNwei_mengmian);

virtual void create()
{
	set_name("����Ů��", "nv lang");
	set("long","���Ǹ���Ľ��õ�Ů��, ��ɴ����,һ˫��Ŀ��͸��һ˿ɱ����");
	set("gender", "Ů��");
	set("age", 20);
	
	set("attitude", "peaceful");
 	set("icon",young_woman11);
	
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("hp", 5000);
	set("max_hp", 5000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 100000);

	set_skill("force", 100);
    set_skill("dodge", 100);
    set_skill("parry", 100);
	set_skill("unarmed", 100);
    set_skill("jiuyang_shengong", 100);
	set_skill("lingfa", 100);
	set_skill("shenghuo_lingfa", 100);
	set_skill("qiankun_danuoyi", 100);
	set_skill("shenghuo_xinfa", 100);
	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");
	
	carry_object("shenghuo_ling")->wield();

	call_out(do_die, 900);	
	set("no_kill",1);
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));
		if(me)
		{
			me->set_temp("wei/renwu6_10",1);
			tell_object(me, "\n$YEL����Ů�ӿ���һЦ�������������а��֣����������ˡ�\n");
			tell_object(me, "$YEL˵�գ�����Ȧ�⣬��������Ͳ�����Ӱ��");
		}
	}
	destruct(this);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}
NPC_END;