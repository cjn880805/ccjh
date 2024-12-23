//meipo.h
//code by zwb
//12-25

NPC_BEGIN(CNpub3_meipo);


virtual void create()
{
	
	set_name("�հ���Ů","kongbai yaonv");

	set("icon", young_woman1);
	set("title", "����ׯ");
	set("gender", "����" );
	set("age", 43);
	set("per", 3);
	set("long","һ��û�У���Ŀ�ݵ���");
	
	set("max_hp", 2400);
	set("combat_exp", 10000);
	set("attitude", "friendly");

	set_inquiry("��ʾ����","�ս�飿�����������������������֪������" );
	
	set_skill("literate", 70);
	set_skill("dodge", 200);
	set_skill("unarmed", 100);
	set("no_huan",1);
//	carry_object("cloth")->wear();
}

virtual int accept_object(CChar * who, CContainer * ob)
{

	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")>=200000 && who->query_temp("teapot/m_m"))
	{
		destruct(ob);
		message_vision("�հ���Ů����һЦ����ָ�ڴ��ߴ���һ��������ֻ��һ���������ĸ������ƿն�ȥ��",who);

		who->delete_temp("teapot/m_m");

		g_player(who, who->querystr("couple/id"));
		g_lost();

		return 1;
	}

return 0;
}

int g_player(CChar * me, string id)
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
	
		char msg[255];
		
//			g_Channel.do_channel(&g_Channel, 0, "wiz", 
//				snprintf(msg, 255, "%s Founded��", obj->name(1) ));


//		if (obj->querystr("id")==id || obj->querystr("id")==me->querystr("id"))
//			continue;

		CContainer * gift;

		snprintf(msg, 255, "����Ʈ��������һ�����ӣ���ƫ����������Ļ��С���\n���һ����������һ��ϲ����һƿ�ƺ�һ�鵰�⡣");
		
		//һֻ�������������������㣺%s��%s����ˡ���",me->name(1),me->querystr("teapot/marryname").c_str());
		
        tell_object(obj,msg);

		gift=load_item("cake");
		gift->move(obj);

		if (EQUALSTR(obj->querystr("gender"), "����"))	//��Ҷ��
		{
			gift=load_item("jiuping2");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "Ů��"))	//Ů����
		{
			gift=load_item("nverhong");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "����"))	//׳����
		{
			gift=load_item("jiuping");
			gift->move(obj);
		}
		
		snprintf(msg, 255, "%s��%s�Ľ��ϲ��",me->name(1),me->querystr("couple/name"));

		gift=load_item("anmenkey");
		gift->set_name(msg, "xi tie");
		gift->set("value",0l);
		gift->set("long",msg);
		gift->set("unit","��");
		gift->move(obj);
    }
    
	return 1;
}

int g_lost()
{
	return 1;
}

NPC_END;