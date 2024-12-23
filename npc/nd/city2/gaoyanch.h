// gaoyanchao.h ���峬
//zhangdn 2001-07-18


NPC_BEGIN(CNcity2_gaoyanchao);

virtual void create()
{
	set_name("�߹���", "gao yanchao");
	set("title", "��ػ���ľ�û���");
	set("gender", "����");
	set("age", 32);
	set("str", 25);
	set("dex", 20);
	set("int", 20);
	set("con", 20);
	set("long", "��������ʮ��ͷ��ȴ�Ե��쳣������һ�Բ��������Ƕ�һվ��\n"
            "�����������ݡ�\n");
	set("combat_exp", 40000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("icon",young_man2);

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
	
	set("hp", 1000);
	set("max_hp", 1000);
	set("mp", 250); 
	set("max_mp", 250);
	set("mp_foctor", 35);
        set_inquiry("�½���",  "����ܶ����ɲ����װ���");
	set_inquiry("��ػ�",  "ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��");
	set_inquiry("���",  "ֻҪ��������ػᣬ��������и�λ����ѧ���ա�");
        set_inquiry("���帴��",  "ȥ�ײĵ�������ϸ���ưɣ�");
        set_inquiry("����", "�����£�");
        set_inquiry("�п�", "�����£�");

//	"����" :  (: ask_weiwang :),
//	"��������" : (: ask_weiwang :),

          carry_object("cloth")->wear();
  
}
/*
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n���峬˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("���峬��˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}

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

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="gao" )
		return 0;
	if(wizardp(ob)) return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
		return 1;
	}

   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �������� (club)                          - �Ƿ��켫  80/    \n"+
"  �����Ṧ (dodge)                         - �����뻯  70/    \n"+
"  �����ڹ� (force)                         - �����뻯  70/    \n"+
"����Ԫһ���� (hunyuan_yiqi)                - ����似  60/    \n"+
"  ����д�� (literate)                      - �������  50/    \n"+
"  �����м� (parry)                         - �����뻯  70/    \n"+
"�������� (shaolin_shenfa)                - ����似  60/    \n"+
"  ����ȭ�� (unarmed)                       - �����뻯  70/    \n"+
"��������� (zui-gun)                       - �����뻯  70/    \n");
return 1;
}
#include "/kungfu/class/yunlong/tiandihui.h";
*/

NPC_END;