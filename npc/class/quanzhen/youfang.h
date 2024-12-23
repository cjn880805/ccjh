// quanzhen_youfang.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_youfang);

virtual void create()
{
	set_name("�η�����", "youfang daoren");
	set("long","����һλδͨ���ʵ�������ˣ����Ϲ��ź������΢Ц��");
	
	set("gender", "����");
	set("attitude", "heroism");
	set("class", "taoist");
	set("icon",taoist_with_sword);
			set("foolid",42);
	set("age", 20);
	set("shen_type", 1);
	set("str", 15);
	set("int", 30);
	set("con", 30);
	set("dex", 18);
	set("max_hp",  900);
	set("hp", 300);
	set("mp", 380);
	set("max_mp", 380);
	set("mp_factor", 27);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("chat_chance", 30);
	
	set_skill("force", 41);
	set_skill("strike", 41);
	set_skill("dodge", 41);
	set_skill("parry", 41);
	set_skill("jinyan_gong", 42);
	set_skill("haotian_zhang", 41);
	set_skill("xiantian_qigong", 41);
	
	map_skill("force", "xiantian_qigong");
	map_skill("dodge", "jinyan_gong");
	map_skill("strike", "haotian_zhang");
	map_skill("parry", "haotian_zhang");
	create_family("ȫ���", 4, "����");
	
	carry_object("cloth")->wear();
}

virtual char * chat_msg()
{
	return "�η�����˵��: ����λʩ�����������Ӹ�ƶ������ϲ��ϲ���츣������";
}	
/*
virtual int accept_object(CChar * me, CContainer * ob)
{
	CContainer * ling;
	char msg[255];
	command("smile");
	say(snprintf(msg,255," �����ٷ𣬶�л��λ%s !" , query_respect(me) ), me);
	
	if( ( (ob->querystr("base_name") ) == "coin" )&& ob->query("value") >= 10000 && DIFFERSTR(me->querystr("class"), "bonze") ) 
	{
		say(snprintf(msg,255,"%s������ƺ�ʩ�����������գ�ȫ����ʦ����һ�����º��ܣ���֪��Ը����������һ�Σ�", query_respect(me) ), me);
		
		ling=load_item("tie_ling");//û�и���Ʒ
		ling->move(me);
		message_vision("�η����˸�$Nһ���������ơ�", me);
		
		say("������ʱһ�գ���ʱʧЧ��������ʱǰ�빬��������в��㣬�м��мǣ�", me); 
	}

	SendMenu(me);	
	return 1;
}
*/
NPC_END;