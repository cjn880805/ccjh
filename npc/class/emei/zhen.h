//zhen.h
//Lanwood 2000-01-05

EMEIBONZE_BEGIN(CNemei_zhen);

virtual void create()
{
	set_name("����ʦ̫", "ningzhen shitai");
	set("long", "����һλ������ҵ��ã������ۣ��������������ϣ�üĿ֮����һ�����֮����");
	set("gender", "Ů��");
	set("icon", taoistess);
	
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 10000);
	set("class", "bonze");
	set_inquiry("���",  ask_for_join);
	set_inquiry("����", "���ҵ��ӣ����ܻ��ס���������ʦ̫�ɡ�");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);
	set("foolid",15);	
	set("max_hp", 3000);
	set("mp", 1500);
	set("max_mp", 1500);
	
	set("combat_exp", 150000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("throwing", 60);
	set_skill("force", 60);
	set_skill("dodge", 70);
	set_skill("finger", 75);
	set_skill("parry", 70);
	set_skill("strike", 60);
	set_skill("sword", 80);
	set_skill("literate", 70);
	set_skill("mahayana", 60);
	set_skill("jinding_zhang", 60);
	set_skill("tiangang_zhi", 65);
	set_skill("huifeng_jian", 60);
	set_skill("zhutian_bu", 60);
	set_skill("linji_zhuang", 60);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_jian");
	map_skill("parry","huifeng_jian");
	
	create_family("������", 4, "����");
	
	setup();
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

   if( DIFFERSTR(me->querystr("class"), "bonze") )
   {
      say("�����ӷ�ƶ�᲻���׼ҵ��ӡ�ʩ������ѧ�տ�ȥ�����׼�ʦ�á�", me);
	  SendMenu(me);
      return;
   }

   if( DIFFERSTR(me->querystr("gender"), "Ů��") )
   {
      say("�����ӷ�ƶ�᲻���е��ӡ�ʩ������ѧ�տ�ȥ�����׼�ʦ�á�", me);
	  SendMenu(me);
      return;
   }

   if (me->query("repute") < 100)
   {
      say(snprintf(msg, 255, "%s����������֮�»����Ĳ�����", query_respect(me)), me);
	  SendMenu(me);
      return;
   }

   say("�����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
   say("ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������");
   command(snprintf(msg, 255, "recruit %ld", me->object_id()));
}

EMEIBONZE_END;
