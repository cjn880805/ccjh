// jia.h ������ 
//zhangdn 2001-07-18

NPC_BEGIN(CNcity2_jialaoliu);
  virtual void create()
{
	
	set_name("������", "jia laoliu");
	set("title", "��ػ���ľ�û���");
//	set("title", "�����ϰ�");
	set("shen_type", 1);

	set("gender", "����");
//	set_max_encumbrance(100000000);
	set("age", 35);
	set("long","������ػ���ľ�û��ڣ�����������֮ʱ�����������ɣ������ǲ���ɱ���췴��ֻ����˽©˰����û���ӵ�С���⣬������������������׷ɱ��éʮ��Ҳ��˺���������\n");
	set("no_get_from", 1);
	set("icon",young_man3);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);
	
	set_inquiry("�½���", "����ܶ����ɲ����װ���");
	set_inquiry("��ػ�",  "ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��");
	set_inquiry("���", "ֻҪ��������ػᣬ��������и�λ����ѧ���ա�");
	set_inquiry("���帴��", "ȥ���׳��͹ײĵ���ϸ���ưɣ�");
//        set_inquiry("����",  (: ask_weiwang :),
//                "��������" : (: ask_weiwang :),	"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
	set_inquiry("���", "ֻҪ��������ػᣬ��������и�λ����ѧ���ա�");
	set_inquiry("���帴��",  "ȥ���׳��͹ײĵ���ϸ���ưɣ�");
 //       set_inquiry("����",  (: ask_weiwang :),
//                "��������" : (: ask_weiwang :),

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("chat_chance", 3);
}

	virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(3))
	{
	case 0:
		return 	"�����ߺ�Ȼ˵�������η�����ɶ�";
	case 1:
		return  "������˵: ������������Ҫ������ֵ�ߴ��кô�����";
        case 2:
		return  "������ͻȻ˵��: ������ǰ�ֵ��ڣ����е㽫�������";
	}
        return 0;
}
/*
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
//       add_action("do_join","join");
}

void die()
{
	message_vision("\n$N��е����ֵ��ǻ����ұ���ģ�ͷһƫ�����ˡ�\n", this_object());
	destruct(this_object());
}
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n������˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("��������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}
// #include "/kungfu/class/yunlong/tiandihui.h";
*/
NPC_END;