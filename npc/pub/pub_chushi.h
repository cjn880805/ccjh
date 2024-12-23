// pub_chushi.c
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_chushi);

virtual void create()
{
	set_name("��ʦ", "chu shi");

	set("icon", pub_boss);
	set("title", "÷ׯ");
	set("long",	"÷ׯ��һ����ʦ��Ц���еؿ����㣬�����ܺ��Ƶ����ӡ�");
	set("gender", "����");
	set("age", 34);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	
	set("max_hp", 600);
	set("mp", 0l);
	set("max_mp", 0l);
	set("mp_factor", 0l);
	set("combat_exp", 500);
	set("repute",0l);
	
	set("no_get",1);
	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("cuff", 10);
	set_skill("parry", 10);
	
	create_family("÷ׯ", 3, "����");
	set_inquiry("�Է�" ,ask_me);
}

static char * ask_me(CNpc * who, CChar * me)
{
	static char msg[255];
	if (DIFFERSTR(me->querystr("family/family_name"), "÷ׯ"))
		return snprintf(msg,255,"%s�뱾��������������֪�˻��Ӻ�̸��",query_respect(me));
	
	me->receive_healing("hp", 100);
	me->SendState(me);
	
	return "�����ԣ���ҭס�ˡ�";
}

NPC_END;