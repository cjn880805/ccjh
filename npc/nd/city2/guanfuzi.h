// guanfuzi.h �ذ���
//zhangdn 2001-07-18 



NPC_BEGIN(CNcity2_guanfuzi);

virtual void create()
{
	set_name("�ذ���", "guan anan");
	set("title", "��ػ���ľ�û���");
//	set("title", "����ϰ�");
	set("nickname", "�ط���");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 35);
	set("long","ֻ���������ĺ���Ʈ����ǰ��ģ���������ϡ�����˳ƹط��ӡ�");
	set("icon",young_man2);

	set_skill("unarmed", 60);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("force", 70);
	set_skill("zixia_shengong", 50);
	set_skill("huashan_sword", 70);
	set_skill("huashan_shenfa",60);
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "huashan_sword");
	map_skill("sword", "huashan_sword");
	map_skill("force", "zixia_shengong");

	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 25);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("chat_chance", 1);
	
	set_inquiry("�½���", "����ܶ����ɲ����װ���");
	set_inquiry("��ػ�", "ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��");
	set_inquiry("���", "ֻҪ��������ػᣬ��������и�λ����ѧ���ա�");
        set_inquiry("���帴��",  "ȥ���׳��͹ײĵ���ϸ���ưɣ�");
 //       set_inquiry("����"  (: ask_weiwang :),
 //               "��������" : (: ask_weiwang :),
}

virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(2))
	{
	case 0:
		return 	"�ذ��غ�Ȼ˵�����õ�����˭���������ֲ�����˵����";
	case 1:
	        return  "�ذ��غ�Ȼ˵�������ҵ�Ƣ������ã���ҿ�ҪС���ˡ�";
	}
	return 0;
}

/*
int recognize_apprentice(object ob)
{
    if (ob->query("weiwang")<50)
    {
    message_vision("$Nҡ��ҡͷ��\n",this_object());
    command("tell "+ob->query("id")+" ������ػ�����Ҳ��̡�\n"); 
    return 0;
    }
    return 1;
}

void init()
{
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}

int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="guan" )
     return 0;
   if(wizardp(ob))   return 0;
  if (ob->query("weiwang")<50)
  {
   message_vision("$Nҡ��ҡͷ��\n",this_object());
   command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
   return 1;
   }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����Ṧ (dodge)                         - �����뻯  70/    \n"+
"  �����ڹ� (force)                         - �����뻯  70/    \n"+ 
"����ɽ���� (huashan-jianfa)                - ����似  70/    \n"+
"����ɽ�� (huashan-shenfa)                - ����似  60/    \n"+
"  �����м� (parry)                         - �����뻯  70/    \n"+
"  �������� (sword)                         - �Ƿ��켫  80/    \n"+
"  ����ȭ�� (unarmed)                       - ����似  60/    \n"+
"����ϼ�� (zixia_shengong)                - �������  50/    \n");
   return 1;
}

void die()
{
message_vision("\n$N��ŭ��������ҿ����ӣ��ֵ��ǻ����ұ���ģ���˵�굹�����ˡ�\n", this_object());
::die();
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n�ذ���˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("�ذ�����˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}
#include "/kungfu/class/yunlong/tiandihui.h";
*/

NPC_END;