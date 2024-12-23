// wuliuqi.h  ������
//zhangdongni  2001-07-18

NPC_BEGIN(CNcity2_wuliuqi);

virtual void create()
{
	set_name("������", "wu liuqi");
	set("title", "��ػ��˳������");
	set("nickname", "��ؤ");
	set("gender", "����");
	set("age", 50);
	set("long","����Ͻл����������������ġ���ؤ�������֣���������������ڹپӹ㶫�ᶽ֮ʱ������һʡ�ر������˲���諵�Ȱ�����Ĵ淴�帴��֮־��������ػᣬ��ְ��˳��������");
	set("attitude", "peaceful");
	set("icon", old_man1);
	set("str", 30);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("hp", 3000);
	set("max_hp", 3000);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_foctor", 150);
	
	set("combat_exp", 150000);
	set("score", 30000);
	
	set_skill("force", 100);			// �����ڹ�
	set_skill("huntian_qigong", 90);	// ��������
	set_skill("unarmed", 90);		// ����ȭ��
	set_skill("xianglong_zhang", 85);	// ����ʮ����
	set_skill("dodge", 90);			// ��������
	set_skill("xiaoyaoyou", 95);		// ��ң��
	set_skill("parry", 85);			// �����м�
	set_skill("begging", 50);		// �л�����
	set_skill("checking", 50);		// ����;˵
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	
	set_inquiry("�½���",  "����ܶ����ɲ����װ���");
	set_inquiry("��ػ�", "ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��");
	set_inquiry("���",  "ֻҪ��������ػᣬ��������и�λ����ѧ�书��");
        set_inquiry("���帴��", "ȥҩ�̺͹ײĵ���ϸ���ưɣ�");
//      "����" :  (: ask_weiwang :),
//      "��������" : (: ask_weiwang :),
	
	set("chat_chance", 1);
	
	carry_object("cloth")->wear();
}

virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(5))
	{

	case 0:
		    return "�����ֺ�Ȼ�ſ������������������߽��ߣ���ǻ�ߺ���˭�ԣ�����������";
	case 1:
	        return "���������������ζ������¸����̡������Դ��У�������Զ��";
	case 2:
	        return "������˵:�� ������������Ҫ�������ߴ��кô�������";
	case 3:
	        return "������ͻȻ˵��:�� �ɰض�֦�����ң��нں黪����ͤ����";
    case 4:
            return "������ͻȻ˵��: ��������ǰ����Ը�����帴���Һ�Ӣ����";
    }
        return 0;
}
        
/*	
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n������˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("\n��������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}

int recognize_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ�����Ҳ��̡�\n"); 
		return 0;
	}
	return 1;
}

void init()
{
	::init();
	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_join","join");
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="wu" )
		return 0;
	if(wizardp(ob))
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
		return 1;
	}
	command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �л����� (begging)                       - �������  50/   \n"+ 
"  ����;˵ (checking)                      - �������  50/   \n"+ 
"  �����Ṧ (dodge)                         - һ����ʦ  90/   \n"+ 
"  �����ڹ� (force)                         - һ����ʦ  95/   \n"+ 
"���������� (huntian-qigong)                - һ����ʦ  90/   \n"+
"  �����м� (parry)                         - �Ƿ��켫  85/   \n"+
"  ����ȭ�� (unarmed)                       - һ����ʦ  90/   \n"+
"������ʮ���� (xianglong-zhang)             - �Ƿ��켫  85/   \n"+
"����ң�� (xiaoyaoyou)                      - һ����ʦ  95/   \n");
	return 1;
}
#include "/kungfu/class/yunlong/tiandihui.h";
*/

NPC_END;