// shenlong_su.c ����

//code by Fisho
//date:2000-12-22

NPCSHENLONG_BEGIN(CNshenlong_su);

virtual void create()
{
	set_name("����", "su quan");
	set("title",  "����" );
	set("long", "�����������̽����鰲ͨ�ķ��ˡ� ");
	set("gender", "Ů��");
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
 	set("icon",young_woman3);
	
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	set("combat_exp", 1500000);
	set("score", 400000);
	
	set_skill("force", 150);
	set_skill("shenlong_xinfa", 150);
	set_skill("dodge", 180);
	set_skill("yixingbu", 160);
	set_skill("unarmed", 150);
//	set_skill("shenlong_quanfa", 150);		//û�иü��� lanwood 2000-12-29
	set_skill("parry", 150);
	set_skill("staff", 150);
	set_skill("strike", 180);
	set_skill("shedao_qigong", 120);
	set_skill("literate", 100);
//	set_skill("meiren_sanshi", 180);		//û�иü��� lanwood 2000-12-29
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
//	map_skill("strike", "meiren_sanshi");
//	map_skill("unarmed", "shenlong_quanfa");
//	map_skill("parry", "meiren_sanshi");
	map_skill("staff", "shedao_qigong");
	set_inquiry("���"," һ�������벻���������̵�. ");
	set_inquiry("�ں�"," ���겻��!�����ɸ�!��������!������ʥ! ");
	
	set("chat_chance_combat", 50);  
	carry_object("cloth")->wear();
	add_money( 5000);
}

virtual char * greeting(CChar * ob)
{
	if (userp(ob))
	{
		if (ob->present("usedgao"))    
			set("combat_exp",500000);
		set("hp",10);
	}
	return "";
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if (ob->query_skill("shenlong_xinfa",1) < 80 ) 
	{
		say(" ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!", ob);
		SendMenu(ob);
		return;
	}
	if (ob->query_skill("shedao_qigong",1) < 80 ) 
	{
		say(" ��ı����ȷ�̫����,����ŬŬ�������һ�°�!", ob);
		SendMenu(ob);
		return;
	}
	if (ob->query("repute") > -10000  ) 
	{
		say(" �������������������������������ְ׵�����򽻵�������ذɣ�", ob);
		SendMenu(ob);
		return;
	}

	say(" �ܺã��ܺá�");
	command(snprintf(msg,255,"recruit %ld" ,ob->object_id() ));
}

NPCSHENLONG_END;