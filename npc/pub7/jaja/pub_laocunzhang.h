// pub_laocunzhang.h �ϴ峤
// dieer 2002 8.6
 
NPC_BEGIN(CNpub_laocunzhang);
 
virtual void create()
{
 set_name("�ϴ峤", "lao cunzhang"  );
 
 set("icon", 19);
 set("gender", "����");
 set("age", 99);
 set("long","���Ǹ��Ͱ����Ҳ�ѧ�����ˣ�����������������ʲô��������飬��ϲ������������Ѱ��𰸣�");
 set("attitude", "friendly");
 set("chat_chance", 3);
 set("per", 40);
 
 set_inquiry("����", ask_shenwang );
 set_inquiry("����", "������Ҫ�Լ�ȥ����");
 set_inquiry("�书", "Ʒ�в��õ��ˣ��书��ǿ��Ҳû���˻ῴ����");
 set_inquiry("����", "��һ�뽭�����´ߡ����뽭�����������ᵽʲô�����ڽ������������ˣ�");
 
 carry_object("cloth")->wear();
 carry_object("walkingstick")->wear();
}
 
virtual char * chat_msg()
{
 switch (random(2))
 {
 case 0:
  return  "�ϴ峤���������׵ĳ��룬�������ؿ�����Ц��Ц��";
 case 1:
  return  "�ϴ峤����˵�������ӣ��ǲ�������үү������ʲô��";
 }
 return "";
}
 
static char * ask_shenwang(CNpc * me, CChar * who)
{
 char msg[255];
 
 me->say("��һЩ�ط������ߵ�ȥ�˻ᰤ��", who);
 me->say("Ҳ��һЩ�ط�����ӭ����̫�͵��ˣ����Ծ���С��Щ��", who);
 me->say("����̫����ˣ�Ƣ��Ҳһ�����ã����Բ�Ҫ����ȥ��ϸ�����ˣ�", who);
if(!who->query("repute"))
 me->say(snprintf(msg, 255, "����Լ�������Ӧ�ú�������Ͳ�Ҫ���������˰ɣ�", who->query("repute")), who);
else
 me->say(snprintf(msg, 255, "�����ڵ�������%d��", who->query("repute")), who);
 
 me->SendMenu(who);
 return 0;
}
 
NPC_END;
