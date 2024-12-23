//pub_ningfeng.h
//wuqing 2001-12-31

NPC_BEGIN(CNpub_ningfeng);

virtual void create()
{	
	set_name("����", "ning yue");
	set("title", "��������İ ");
	set("gender", "Ů��");
	set("icon", young_woman3);
	set("age", 68);
	set("long",  "�����ļ���������ɫ��Ө���񣬽��Ĳ��ɷ��");
	
	set("str", 65);
	set("int", 65);
	set("con", 65);
	set("dex", 65);
	set("per", 40);
	set("max_hp", 35000);
	set("max_mp", 20000);
	set("mp", 20000);
	set("mp_factor", 150); 
	
	set("combat_exp",  8000000);
	set("chat_chance",  1);
	set("chat_chance_combat", 10);
	
	set_inquiry("����", "�������ҿ�ɽ��ʦ�������񣬾�û�¹�˭��ƶ�ᡣ����");
	set_inquiry("����", "��˼�����ϣ��κζ����");
	set_inquiry("��ͥ", "�»���ͥ��");
	
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 350);
	set_skill("literate", 300);
	set_skill("linji_zhuang", 199);
	set_skill("piaoyibu", 300);
	set_skill("huifeng_qijue", 350);
    
	map_skill("force", "linji_zhuang");
	map_skill("dodge", "piaoyibu");
	map_skill("sword", "huifeng_qijue");
	map_skill("parry", "huifeng_qijue");

	carry_object("changjian")->wield();

}

virtual char * chat_msg()				
{
	switch(random(4))
	{
	case 0:
		return "�������ĵ����������䣬��֮����˶ϳ���";
	case 1:
		return "��CC��̾���������粻֪���ɺ� ";
	case 2:
		return "��CC�����˸е����»���ͥ";
	case 3:
		return "����������ҹ�գ���֪����ͥ���ֵܽ���������ô���ˣ���";
	}
	return 0;
}

virtual char * chat_msg_combat()			
{
	switch(random(2))
	{
	case 0:
		perform_action("sword mixhit", 1);	
		break;
	case 1:
		perform_action("force recover", 0);	
		break;
	}	
	return 0;
}

virtual void die()
{
	CContainer * obj = environment();
	char msg[255];
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(!userp(target))	continue;
		if(is_fighting(target)==1 && EQUALSTR(target->querystr_temp("gumu/kill_name"), "����")&& EQUALSTR(target->querystr_temp("gumu/kill_id"), "ning yue"))
		{
			message_vision("\n$N��Ȼ�������ȥ���߰���������Ȼ��$N�������ˣ��ӽ��Ժ��Ҳ��ٹ���������Щ�����ˣ��ط��߾��˳���������������", this);
			target->delete_temp("gumu/kill_name");
			target->delete_temp("gumu/kill_id");
			target->add("combat_exp",target->query_temp("gumu/kill_exp"));
			message_vision(snprintf(msg, 255, "$HIR$N�����%d�������齱����\n",target->query_temp("gumu/kill_exp")), target);
			target->delete_temp("gumu/kill_exp");
			target->add_temp("gumu/jq_renwu",1);
			continue;
		}
	}
	CNpc::die();
}
NPC_END;



