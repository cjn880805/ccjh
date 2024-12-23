// pub_dizi2.c ����
//code by Fisho
//date : 2000-12-13

//inherit F_MASTER;

NPC_BEGIN(CNpub_dizi2)

virtual void create()
{
	set_name("���µ���", "di zi2");
	set("long", "������ʮ�����׳���������Բ���ǵ�������ԭ��ļ���ġ�");
	
	set("icon", triggerman2);
	set("gender", "����");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "peaceful");
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 30);
	
	set("combat_exp", 30000);
	set("score", 10);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("hand", 70);
	set_skill("staff", 50);
	create_family("���͵�", 2, "����");
 
	carry_object("ycloth")->wear();
}

virtual char * greeting(CChar * ob)
{
	char msg[255];
	
	if( !ob || EQUALSTR(environment()->querystr("base_name"), "���͵�ɽ��"))
		return "";
	
	switch( random(2) )
	{
	case 0:
		return snprintf(msg, 255, "��λ%s����ӭ��ӭ��", query_respect(ob)) ;

	case 1:
		return snprintf(msg, 255, "��λ%s��С�����������ˡ�",query_respect(ob)) ;
	}
	return "";
}

NPC_END;