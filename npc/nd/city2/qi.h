// qi.h
//zhangdongni  2001-07-18

NPC_BEGIN(CNcity2_qi);
  virtual void create()
{
	set_name("Ԭ����", "qi fangkai");
	set("long", "��������ݳ���ȴ�������Ѱ�, �ƺ���������ҵ��\n");
	set("gender", "����");
	set("age", 35);
	set("icon", young_man4);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("max_hp", 1500);
	set("hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_foctor", 50);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("hunyuan_zhang", 70);
	set_skill("unarmed",80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);

	map_skill("unarmed", "hunyuan_zhang");
	map_skill("parry", "hunyuan_zhang");

	set("env/wimpy", 60);
	set_inquiry("��ʮ���¾�", "�ף���Ҳ֪�������������б��飿");
	set_inquiry("��", "�ף���Ҳ֪��������������...��");
	set_inquiry("Կ��", "�ף���Ҳ֪��ȡ��Ҫ��Կ�ף�");
	
	set("chat_chance", 1);
	carry_object("cloth")->wear();
}
virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(3))
	{
	case 0:
		return  "Ԭ������Ȼ˵: ������ȡ�����Ҿ��ߡ���";
        case 1:
                return  "Ԭ����һҧ����˵��:��������̫̰�ˣ��³�֮��һ��ɱ������ڡ���";
	case 2:
	        return  "Ԭ�������������: �����У�ֻ�»��л��ء���";
	}
	return 0;        
}
	
NPC_END;