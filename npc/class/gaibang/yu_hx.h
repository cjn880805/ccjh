//yu_hx.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_yu_hx);

virtual void create()
{
	set_name("�����", "yu hongwang");
	set("title", "ؤ��˴�����");
	set("gender", "����");
	set("age", 30);
	set("long", "����λЦ���е�ؤ��˴����ӣ����Զ��ǣ����С���á�");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 30);
	set("con", 22);
	set("dex", 20);
	set("icon",begger);

	set("beggarlvl", 8);

	set("hp", 420);
	set("max_hp", 1500);
	set("mp", 780);
	set("max_mp", 780);
	set("mp_factor", 42);
	set("combat_exp", 82000);
	
	set_skill("force", 108); 
	set_skill("huntian_qigong", 106); 
	set_skill("unarmed", 108); 
	set_skill("xianglong_zhang", 110); 
	set_skill("dodge", 90); 
	set_skill("xiaoyaoyou", 88); 
	set_skill("parry", 81); 
	set_skill("begging", 80); 
	set_skill("stealing", 90); 
//	set_skill("checking", 70); 
	set_skill("xunshou_shu", 70);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 19, "����");
	set("no_huan",1);
	
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if( me->query_int() < 25 )
	{
		say("�����������Ϊ����ֻ���߹������˼Һ��Ҳ��ر���Щ����ͽ������Ҷ�ҪΪ��Զ���밡���㿴����������");
		return;
	}
	if( me->query("combat_exp") < 50000 )
	{
		say("��������������Զ����");
		return;
	}
	if( me->query("repute") < 0 )
	{
			say("��������������Ϊ��ּ���㣿");
		return;
	}
	else
	{
		say ("�ðɣ�ϣ�����ܺú�ѧϰ�����书������Ϊؤ����һ��������");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("class", "beggar");
		return;
	}
	return;
}


NPC_END;
