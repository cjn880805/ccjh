// pub_laocunzhang.h 老村长
// dieer 2002 8.6
 
NPC_BEGIN(CNpub_laocunzhang);
 
virtual void create()
{
 set_name("老村长", "lao cunzhang"  );
 
 set("icon", 19);
 set("gender", "男性");
 set("age", 99);
 set("long","他是个和蔼而且博学的老人，村里的人如果碰上了什么不解的事情，总喜欢到他这里来寻求答案！");
 set("attitude", "friendly");
 set("chat_chance", 3);
 set("per", 40);
 
 set_inquiry("声望", ask_shenwang );
 set_inquiry("人生", "人生需要自己去感悟！");
 set_inquiry("武功", "品行不好的人，武功再强，也没有人会看得起。");
 set_inquiry("江湖", "“一入江湖岁月催”进入江湖，你就能体会到什么是人在江湖，身不由已了！");
 
 carry_object("cloth")->wear();
 carry_object("walkingstick")->wear();
}
 
virtual char * chat_msg()
{
 switch (random(2))
 {
 case 0:
  return  "老村长捋了捋银白的长须，满面慈祥地看着你笑了笑！";
 case 1:
  return  "老村长对你说道：孩子，是不是想向爷爷打听点什么？";
 }
 return "";
}
 
static char * ask_shenwang(CNpc * me, CChar * who)
{
 char msg[255];
 
 me->say("有一些地方声望高的去了会挨打！", who);
 me->say("也有一些地方不欢迎声望太低的人，所以尽量小心些！", who);
 me->say("声望太差的人，脾气也一定不好，所以不要轻易去仔细看别人！", who);
if(!who->query("repute"))
 me->say(snprintf(msg, 255, "你对自己的声望应该很清楚，就不要来考老朽了吧！", who->query("repute")), who);
else
 me->say(snprintf(msg, 255, "你现在的声望是%d。", who->query("repute")), who);
 
 me->SendMenu(who);
 return 0;
}
 
NPC_END;
