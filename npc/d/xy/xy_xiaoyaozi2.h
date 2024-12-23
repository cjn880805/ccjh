//xy_xiaoyaozi2.h ��ң�ӣ���ң��СԺ����NPC��
//�ز� 2002��12��12

NPC_BEGIN(CNxy_xiaoyaozi2);

virtual void create()
{    
    set_name("��ң��", "xiaoyao zi");
    set("long","ֻ�����촽ī����������񣬾���Ͷ��֮����ɷ��������ţ�ֱ������ң�������ֵ����쾡�¡�");	
    set("title","��ң��");
	set("gender", "����"); 
    set("age", 23);

    set("str", 30); 
    set("int", 30);
    set("con", 30);
    set("dex", 32);
    set("per", 40);

    set("icon",13);
	create_family("��ң��", 1, "����");

    set("max_hp", 28000);
    set("mp", 9000);
    set("max_mp", 9000);
    set("mp_factor", 80); 
    set("combat_exp", 90000000); 
	
	set("no_kill",1);

    set_skill("force", 400);
    set_skill("beiming_shengong", 400);
    set_skill("dodge", 400);
    set_skill("lingboweibu", 400);
	set_skill("xiaoyao_bu", 400);
    set_skill("unarmed", 400);
    set_skill("liuyang_zhang", 400);
    set_skill("parry", 400);
    set_skill("blade", 400);
    set_skill("xiaoyao_dao", 400);
    set_skill("zhemei_shou", 400);
    set_skill("hand", 400);
	set_skill("lingxiao_kuaijian", 400);
	set_skill("xiaoyao_jian", 400);
	set_skill("sword", 400);
	set_skill("literate", 300);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "lingxiao_kuaijian");
    map_skill("blade", "xiaoyao_dao");
	map_skill("sword", "xiaoyao_jian");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");

    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("changjian")->wield();

	call_out(do_die, 900);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR((me->environment())->querystr("base_name"), "��ң��СԺ" ))
	{
		if(me->query("xy/renwu7_2") && me->query_temp("xy/renwu7_3") && me->query("xy/renwu7_3")<1)
		{
			if(! strlen(ask))
			{
				AddMenuItem("������׺�","li",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "li") )
			{
				say("��ң��������˼�ġ�����һ����ȴ��δ�ش���Ļ���",me);
				SendMenu(me);
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

NPC_END;




