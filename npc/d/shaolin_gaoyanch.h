// shaolin_gaoyanch.c ���峬

//code by Fisho
//date:2000-12-21
//inherit F_UNIQUE;
//inherit F_MASTER;

NPC_BEGIN(CNshaolin_gaoyanch);

virtual void create()
{
	set_name("��˪��",  "gao yanchao");
	set("title",  "��ػ���ľ�û���");
	set("gender", "����");
	set("age", 32);
	set("str", 25);
	set("dex", 20);
	set("long", "��������ʮ��ͷ��ȴ�Ե��쳣������һ�Բ��������Ƕ�һվ�������������ݡ�");
	set("combat_exp", 40000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
        set("icon",young_man1);
	
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("club", 80);
	set_skill("parry", 70);
	set_skill("literate", 50);
	set_skill("hunyuan_yiqi", 60);
	set_skill("shaolin_shenfa", 60);
	set_skill("zui_gun", 70);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("club", "zui_gun");
	map_skill("parry", "zui_gun");
	
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 25);
	set("hp", 400);
	set("max_hp", 1200);
	set("mp", 250); 
	set("max_mp", 250);
	set("mp_factor", 35);

	set_inquiry("��Զ��","����ܶ����ɲ����װ���");
	set_inquiry("��ػ�","ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��");
	set_inquiry("���","ֻҪ��������ػᣬ��������и�λ����ѧ���ա�");
	set_inquiry("���帴��","ȥ�ײĵ�������ϸ���ưɣ�");
	set_inquiry("����","�����£�");
	set_inquiry("��������",ask_weiwang);
 	
	carry_object("qimeigun")->wield();
	carry_object("cloth")->wear();
	add_money( 1000);
}

static char * ask_weiwang(CNpc *who ,CChar *me)
{
	char msg[255];
	who->say(snprintf(msg,255,"�����ڵĽ���������%ld",me->object_id(),me->query("weiwang") ), me);
	who->say("���������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦���������㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������", me);
	who->say("ɱĳЩ���˻��ĳЩ���˿�����߽���������", me);
	who->SendMenu(me);
	return "";
}
/*
virtual void init(CChar *me)
{
	CNpc::init(me);
	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_join","join");
}
*/
virtual int recognize_apprentice(CChar * ob)
{
    if (ob->query("weiwang")<50)
		return 0;

	return 1;
}

int do_skills(CChar *ob,char * arg)
{
	char msg[255];
	if( !arg || arg!="gao" )
		return 0;
	if(wizardp(ob)) return 0;
	if (DIFFERSTR(ob->querystr("party/party_name"), "��ػ�")  )
	{
		message_vision("$Nҡ��ҡͷ��",this);
		command(snprintf(msg,255,"tell %ld  ������ػ���Ӳ��ܲ쿴��",ob->object_id() )); 
		return 1;
	}
	
	//command(snprintf(msg,255,"tell %ld  �����е��书���£�   �������� (club)  - �Ƿ��켫  80/       �����Ṧ (dodge)  - �����뻯  70/       �����ڹ� (force)  - �����뻯  70/     ����Ԫһ���� (hunyuan_yiqi)  - ����似  60/       ����д�� (literate)  - �������  50/       �����м� (parry) - �����뻯  70/     �������� (shaolin_shenfa) - ����似  60/       ����ȭ�� (unarmed) - �����뻯  70/     ��������� (zui_gun) - �����뻯  70/    ",ob->object_id() ));
	return 1;
}

NPC_END;