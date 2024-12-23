//bj_wangqiuren.h	��������
//�ز� 2003��6��5

NPC_BEGIN(CNbj_wangqiuren);

void create()
{
	set_name("������","wang	qiu ren");
	set("long", "�����ʹ�������Ũü��Ŀ��������ף���һ���ķ�˪һ������������ս����������߰˳ߣ�վ����������棬�˵��Ǻ����ࡣ");
	set("title", "��ָ��ʹ");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("icon",general);
	set("per", 10);
	set("str", 41);
	set("int", 24);
	set("con", 38);
	set("dex", 32);
	set("no_kill",1);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

	set("combat_exp", 800000);

    set_skill("force", 260);
    set_skill("beiming_shengong", 260);
    set_skill("dodge", 260);
    set_skill("guimei_shenfa", 260);
    set_skill("unarmed", 260);
    set_skill("liuyang_zhang", 260);
    set_skill("parry", 260);
    set_skill("club", 260);
    set_skill("xiaoyao_dao", 260);
    set_skill("zhemei_shou", 260);
    set_skill("hand", 260);
	set_skill("zhanjiang_jue", 300);
	set_skill("zhongpingqiang", 300);
	set_skill("wuhuduanmendao", 300);

    map_skill("force", "beiming_shengong");
    map_skill("dodge", "guimei_shenfa");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "zhanjiang_jue");
    map_skill("club", "zhanjiang_jue");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 180);
    set("apply/damage", 200);
    carry_object("huaji")->wield();

	set("chat_chance_combat", 30);
	
};

virtual void die()
{
	CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query_temp("zhang/����ǿ_jion"))
		{			
			tell_object(me, "\n$HIR���������澪��Ŀ����㣬�������۹��ƺ��������Լ���������ĵ�����ȥ��\n");
			me->set("zhang/renwu6_end",1);
			load_room("�����о�˧��")->del("ok");
		}
	}
	CNpc::die();
}

virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("club killyou", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	}
	return 0;
}

NPC_END;




