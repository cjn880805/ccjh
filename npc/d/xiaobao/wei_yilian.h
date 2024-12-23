// wei_yilian.h ����
// �ز�	2002��12��25

NPC_BEGIN(CNwei_yilian);

virtual void create()
{
	set_name("����", "yi lian" );
	set("gender", "Ů��");
	set("icon", young_woman3);
	set("long",  "�����ĺ�������ȴ˫ü�������ƺ��������޵����¡�");
	set("age", 22);
	set("per",34);

	set_weight(50000000);

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("hp", 22000);
    set("max_hp", 22000);
    
    set("mp", 10000);
    set("max_mp", 10000);
    set("mp_factor", 120);

    set("combat_exp", 17000000);

	set_skill("force", 330);
    set_skill("dodge", 280);
    set_skill("parry", 280);
	set_skill("unarmed", 300);
    set_skill("jiuyang_shengong", 330);
	set_skill("lingfa", 300);
	set_skill("shenghuo_lingfa", 300);
	set_skill("qiankun_danuoyi", 300);
	set_skill("shenghuo_xinfa", 280);
	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 150);
	set_temp("apply/damage", 130);
	
	carry_object("shenghuo_ling")->wield();
	set("no_kill",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!querystr("owner")[0])
	{
		if(me->query_temp("wei/renwu8_12"))
		{
			if(me->query_temp("wei/renwu7_6"))
			{
				if(! strlen(ask))
				{
					AddMenuItem("ѯ�ʹ�������","shengshi",me);
					if(me->query_temp("wei/renwu7_7") && !me->query_temp("wei/renwu6_4"))
					{
						AddMenuItem("ѯ�ʹ�����ѩ","zeng",me);
					}
					if(me->query_temp("wei/renwu6_3"))
					{
						AddMenuItem("ѯ�ʹ��ڷ��","fang",me);
					}
					SendMenu(me);
				}
				else if(!strcmp(ask, "shengshi") )
				{
					me->set_temp("wei/renwu7_7",1);//�������Ի�
					tell_object(me,"\n������̾�����ҵ������������������µĴ󽫣���������������Ϊ�˲�����С֮ͽɧ�Ŵ˵أ���һֱ�ػ������");
					tell_object(me,"������̾������񴫵���������������꣡\n");
					if(me->query_temp("wei/renwu6_2"))
					{
						tell_object(me,"������������øУ����������֮����ɱ��������\n");
						me->set_temp("wei/renwu6_3",1);//���������֮��ɱ����
					}
				}
				else if(!strcmp(ask, "fang") )
				{
					tell_object(me,"\n���������������������õģ����Ҳ�������ʲô��");
				}
				else if(!strcmp(ask, "zeng") )
				{
					me->set_temp("wei/renwu7_8",1);//������Ӧȥ����ѩ
					tell_object(me,"\n�����ƺ�����ʲô���飬΢΢һЦ����СѾͷ���þ�û���ˣ���Ҳ�������ġ�");
					tell_object(me,"$HIC���������������ж���\n");
					
					CChar * wei = load_npc("wei_yilian");
					wei->move(load_room("��������"));
					wei->set("owner",me->id(1));
					wei->set_leader(me);
					move(load_room("temp_yl"));
				}
				return 1;
			}
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual void die()
{
	CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query_temp("wei/renwu6_2"))
		{
			me->set_temp("wei/renwu6_4",1);//ɱ������
		}
	}
	CNpc::die();
}

NPC_END;