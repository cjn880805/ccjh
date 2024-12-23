//yan.c
//sound 2001-07-18

NPC_BEGIN(CNtaohua_yan);

virtual void create()
{	
	set_name("��Ӣ", "cheng ying");
//	set_name("�ճ�Ӣ", "yan ruofeng");
	set("gender", "Ů��" );
	set("age",18);
	set("icon",young_woman3);			//������������
	set("long", 
		"��Ӣ�ǻ�ҩʦ��С�����Ĺ�Ů���ɻ�ҩʦ���̵ֽ���һ�����˳ƾ���"
		"����ַ�������һ�������ʳ����������");
	set("per", 30);
	set("class", "scholar");
	set("combat_exp", 10000);
	
	set_skill("unarmed",30);
	set_skill("luoying_shenzhang",30);
	set_skill("dodge", 30);
	set_skill("anying_fuxiang" , 30);
	set_skill("force",30);
	map_skill("dodge", "anying_fuxiang");
	map_skill("unarmed","luoying_shenzhang");
	
	set("force", 500);
	set("max_force", 500);
	set("mp_factor",0l);
	
	set("chat_chance", 7);

	create_family("�һ���", 3, "����");
	
	carry_object("cloth")->wear();
}

virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(3))
	{
	case 0:
		return 	"��Ӣ΢Ц��˵���������һ�����ɫ��������ӭ�����ͣ�";
	case 1:
		return 	"��Ӣ���˵�˵�����Ҽ���������ˣ�";
	case 2:
		return 	"��Ӣ΢Ц��˵�����������������һ������������������µ�һѽ��";
	}	
	return 0;
}
/*
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object teatp,foodtp;
	if( !ob || environment(ob)!=environment() )
		return;
	if ( ob->query_temp("taohua/�跹") )
		say("��Ӣ΢Ц��˵�� ��λ"
		+RANK_D->query_respect(ob)+"����ã���ӭ�����һ�����\n");
	else
	{
		tell_room(environment(this_object()),
			"��Ӣ���ϲ跹��΢Ц��˵������λ" + RANK_D->query_respect(ob)
			+ "����ã���ӭ�����һ��������÷���\n");
		teatp = new("/d/taohua/obj/cha");
		teatp ->move(ob);
		foodtp= new("/d/taohua/obj/gao");
		foodtp->move(ob);
		
		command ("say �������������ģ�����Ʒ����\n");
		ob->set_temp("taohua/�跹", 1);
	}
}
*/
NPC_END;