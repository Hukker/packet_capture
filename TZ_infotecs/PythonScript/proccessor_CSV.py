import csv
from collections import defaultdict

def process_csv(input_file, output_file):
    ip_stats = defaultdict(lambda: {'sent_packets': 0, 'sent_bytes': 0, 'received_packets': 0, 'received_bytes': 0})

    with open(input_file, 'r') as infile:
        reader = csv.reader(infile)
        next(reader)  # Skip header
        for row in reader:
            src_ip, dst_ip, src_port, dst_port, packet_count, byte_count = row
            packet_count = int(packet_count)
            byte_count = int(byte_count)

            # Count sent and received packets/bytes
            ip_stats[src_ip]['sent_packets'] += packet_count
            ip_stats[src_ip]['sent_bytes'] += byte_count
            ip_stats[dst_ip]['received_packets'] += packet_count
            ip_stats[dst_ip]['received_bytes'] += byte_count

    with open(output_file, 'w', newline='') as outfile:
        writer = csv.writer(outfile)
        writer.writerow(["IP Address", "Received Packets", "Received Bytes", "Sent Packets", "Sent Bytes"])
        for ip, stats in ip_stats.items():
            writer.writerow([ip, stats['received_packets'], stats['received_bytes'], stats['sent_packets'], stats['sent_bytes']])

    print(f"Post-processed data saved to {output_file}")

if __name__ == "__main__":
    process_csv('output.csv', 'processed_flows.csv')
