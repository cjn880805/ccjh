//xuan.h
//Lanwood 2000-01-05

EMEIBONZE_BEGIN(CNemei_xuan);

virtual void create()
{
	set_name("����ʦ̫",  "ningxuan shitai");
	set("long",  "���Ƕ����ɴ�ʦ�㣬������ʦ̫��ʮ���أ������ɵĻ��������Ѿ���������");
	set("gender", "Ů��");
	set("icon", taoistess);
	
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 10000);
	set("class", "bonze");
	set_inquiry("���", ask_for_join );
	set_inquiry("����", "���ҵ��ӣ����ܻ��ס���������ʦ̫�ɡ�");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);
	set("foolid",16);	
	set("max_hp", 3000);
	set("max_mp", 500);
	set("mp", 1500);
	
	set("combat_exp", 250000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("throwing", 80);
	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("finger", 95);
	set_skill("parry", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("literate", 90);
	set_skill("mahayana", 100);
	set_skill("jinding_zhang", 100);
	set_skill("tiangang_zhi", 90);
	set_skill("huifeng_jian", 90);
	set_skill("zhutian_bu", 100);
	set_skill("linji_zhuang", 100);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_jian");
	map_skill("parry","huifeng_jian");
	
	create_family("������", 4, "����");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if( DIFFERSTR(me->querystr("class"), "bonze") )
   {
      say("�����ӷ�ƶ�᲻�յ��ӡ�", me);
      say("���������ѧ�����ɵĹ��򣬻���ȥ�����׼�ʦ�ðɡ�", me);
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
      say("����������֮�»����Ĳ�����", me);
	  SendMenu(me);
      return;
   }

   if (me->query_skill("mahayana", 1) < 50)
   {
      say("���˷𷨵���Ϊ��Ҫ���Щ��", me);
	  SendMenu(me);
      return;
   }

   say("�����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
   say("ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������");
   command(snprintf(msg, 80, "recruit %ld", me->object_id()));
}

EMEIBONZE_END;
