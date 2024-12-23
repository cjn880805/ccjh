//lingjiu_wulaoda.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_wulaoda);

virtual void create()
{
	set_name("������",  "wu laoda");
	set("long","���������������İ�����������ı������δ����������ڴˡ�");
	set("gender", "����");
	//	set("title", "����һƷ�ø���");
	//	set("nickname",  "ն������˪��" );
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");
 	set("icon",old_man2);
	
	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);
	
	set("max_hp", 3000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 0l);
	
	set("combat_exp", 1000000);
	set("score", 100000);
	set("chat_chance", 3);
	set("wan_count", 1);
	
	set_inquiry("�����ܵ���",ask_me);
	
}

virtual char * chat_msg()
{
	return "�������૵��������ܵ�������Ǻö�����";
}	

static char * ask_me(CNpc *who,CChar *me)
{
	CContainer *obj;
	if (!(me->querymap("family")) || DIFFERSTR(me->querystr("family/family_name"), "���չ�"))
		//return query_respect(me) + "������Ҫ���չ�֮���ɱ����أ�");
		return "������Ҫ���չ�֮���ɱ����أ�";
	
	if (who->query("wan_count") < 1)
		return "������˼���Ѿ����˽����ȵ��ˣ����´������ɡ�";
	who->add("wan_count", -1);
	obj = load_item("baiyunwan");//�����ܵ���
	obj->move(me);
	return "����������������ҵķ��ϣ���Ű����ܵ���͸���ɡ�";
}

NPC_END;